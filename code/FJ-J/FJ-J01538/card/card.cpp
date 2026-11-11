#include<bits/stdc++.h>
using namespace std;
int n,m,t[1000010],p[1000010],q[1000010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&t[i]);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!p[t[j]]){
				p[t[j]]=j;
			}
			else{
				for(int k=p[t[j]];k<j;k++){
					p[t[k]]=0;
				}
				p[t[j]]=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(p[j])q[j]++;
		}
		fill(p,p+1+m,0);
	}
	for(int i=1;i<=m;i++)cout<<q[i]<<' ';
	return 0;
}
