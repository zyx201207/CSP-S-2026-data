#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[300010];
int len=0,b[300010];
bool val[300010];
void qwe(int x){
	memset(val,0,sizeof(val));
	len=0;
	for(int i=x;i<=n;i++){
		int A=a[i];
		if(val[A]){
			for(int j=1;j<=len;j++){
				if(b[j]==A){
					while(len>j){
						val[b[len]]=0;
						len--;
					}
					break;
				}
			}
		}else{
			val[A]=1;
			b[++len]=A;
		}
	}for(int i=1;i<=len;i++) ans[b[i]]++;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		qwe(i);
	}for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}
