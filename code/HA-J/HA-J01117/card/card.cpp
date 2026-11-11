#include<bits/stdc++.h>
using namespace std;
int n,m;
int num[500005];
int f[300005];
int s[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>num[i];
	}
	for (int i=1;i<=n;i++){
		int t=0;
		for (int j=i;j<=n;j++){
			t++;
			s[t]=num[j];
			for (int k=1;k<=t;k++){
				if (s[k]==num[j]){
					t=k;
					break;
				}
			}
		}
		for (int j=1;j<=t;j++){
			f[s[j]]++;
		}
	}
	for (int i=1;i<=m;i++){
		cout<<f[i]<<' ';
	}
	return 0;
}
