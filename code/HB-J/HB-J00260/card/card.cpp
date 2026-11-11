#include<bits/stdc++.h>
using namespace std;
const int L=5e5+5,M=3e5+5;
int n,m;
int a[L],b[L],c[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++) if(a[j]==a[i]){
			for(int k=j-1;k>=i;k--) b[k]=b[k]-b[i];
			break;
		}
	}
	for(int i=1;i<=n;i++) if(c[a[i]]<b[i]) c[a[i]]=b[i];
	for(int i=1;i<=m;i++) cout<<c[i]<<' ';
	return 0;
}
