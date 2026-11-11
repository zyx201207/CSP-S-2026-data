#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N],t[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int u=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			bool l=0;
			for(int k=i;k<j;k++){
				if(a[k]==a[j]){
					u=k;
				}
			}
		}
		for(int i=u+1;i<=n;i++){
			t[a[i]]++;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<t[i]<<" ";
	}
	return 0;
} 
