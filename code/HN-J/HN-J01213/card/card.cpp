#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n],b[n];
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}

	for(int i=0; i<n; i++) {
		int sum,ans=0;
		ans=0;
		for(int j=i+1; j<=n; j++) {
			b[i]=a[j];
			ans++;
			if(a[j]==b[i]) {
				for(int v=0; v<ans; v++) {
					if(a[i]==b[v]) {
						sum++;
					}
				}
				cout<<sum<<" ";
				i++;
				break;
			}
			i++;
		}
		for(int j=0; j<ans; j++) {
			if(a[i]==b[j]) {
				sum++;
			}
		}
		cout<<sum<<" ";
		i--;
	}
	return 0;
}
