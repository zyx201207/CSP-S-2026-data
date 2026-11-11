#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],sta[300010],top,ans[300010],ins[300010],st1[300010],st2[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		memset(ins,0,sizeof(ins));
		top=0;
		for(int j=i;j<=n;j++){
			if(!ins[a[j]]||st2[st1[a[j]]]!=a[j]||ins[a[j]]>top) {
				sta[++top]=a[j];
				ins[a[j]]=top;
				st1[a[j]]=top;
				st2[top]=a[j];
			}
			else top=ins[a[j]];
		}
		for(int j=1;j<=top;j++) ans[sta[j]]++;
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}
