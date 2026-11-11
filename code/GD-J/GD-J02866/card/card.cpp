#include<bits/stdc++.h> 
using namespace std;
int n,m,a[500010],s[500000],cnt[500000],p[500010],pk;
bool b[500000];
void gl(int j){
	for(int i=j;i<=pk;i++){
		s[p[i]]=0;
		b[p[i]]=0;
		p[i]=0;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		memset(p,0,sizeof(p));
		pk=0;
		for(int j=i;j<=n;j++){
			if(!b[a[j]]){
				b[a[j]]=1;
				pk++;
				p[pk]=a[j];
				s[a[j]]=pk;
			}else{
				if(s[a[j]]) gl(s[a[j]]);
				pk++;
				p[pk]=a[j];
				s[a[j]]=pk;
				b[a[j]]=1;
			}
		}
		for(int j=1;j<=pk;j++) cnt[p[j]]++;
	}
	for(int i=1;i<=m;i++) printf("%d ",cnt[i]);
	return 0;
}
