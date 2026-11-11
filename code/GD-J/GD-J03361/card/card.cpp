//½ä½¾½äÔê£¬¾²ĞÄË¼¿¼ 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,pre;
int a[N];
int ans[M],b[M],c[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		int cur=0;
		for(int j=1;j<=m;j++) b[j]=0;
		for(int j=i;j<=n;j++){
			if(b[a[j]]&&b[a[j]]<=cur){
				cur=b[a[j]];
			}else{
				c[++cur]=a[j];
				b[a[j]]=cur;
			}
		}
		for(int j=1;j<=cur;j++){
			ans[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}

