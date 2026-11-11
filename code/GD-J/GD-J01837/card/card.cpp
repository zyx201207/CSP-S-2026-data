#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m;
int a[N],s[M];
bool v[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int i=1;i<=n;i++){
		memset(v,0,sizeof(v));
		for (int k=i;k<=n;k++){
			if (v[a[k]]){
				int u=k-1;
				while(a[u]!=a[k]){
					v[a[u]]=0;
					u--;
				}
			}
			else v[a[k]]=1;
		}
		for (int k=1;k<=m;k++){
			s[k]+=v[k];
		}
	}
	for (int i=1;i<=m;i++){
		cout<<s[i]<<" ";
	}
	return 0;
}
