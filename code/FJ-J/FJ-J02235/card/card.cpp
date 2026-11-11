#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+50,M=3e5+50;
int c[N],st[N],s[M],n,m;
bool b[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	for(int i=1;i<=n;i++){
//		memset(st,0,sizeof(st));
		memset(b,0,sizeof(b));
		int p=0;
		for(int j=i;j<=n;j++){
			if(!b[c[j]]) {
				st[++p]=c[j];
				b[c[j]]=1;
			}
			else {
				while(st[p]!=c[j])
				b[c[p--]]=0;
			}
		}
		for(int k=1;k<=m;k++){
			if(b[k]) s[k]++;
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",s[i]);
	return 0;
}