#include<bits/stdc++.h>
using namespace std;
long long n,m,b[600000],s[400000],c[400000],x,p;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		memset(c,0,sizeof(c));
		x=i;
		for(int j=i;j<=n;j++){
			if(c[b[j]]!=0){
				if(x==i){
					for(int k=i;k<c[b[j]];k++){
						s[b[j]]++;
					}
				}
				x=j;
			}
			c[b[j]]=j;
		}
		for(int j=x;j<=n;j++)s[b[j]]++;
	}
	for(int i=1;i<=m;i++)cout<<s[i]<<" ";
	return 0;
}
