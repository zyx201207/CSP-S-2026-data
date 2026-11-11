#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],pos[N],q[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool flag=1;
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if (a[i]<a[i-1]) flag=0;
	}
	if (flag){
		for (int i=1;i<=n;i++) ans[a[i]]=i;
		for (int i=1;i<=m;i++) printf("%d ",ans[i]);
		return 0;
	}
	if (m==2){
		if (a[n]==1){
			int cnt=0;
			for (int i=1;i<=n;i++) cnt+=(a[i]==2);
			printf("%d %d",n,cnt); 
		}else{
			int cnt=0;
			for (int i=1;i<=n;i++) cnt+=(a[i]==1);
			printf("%d %d",cnt,n);
		}
		return 0;
	}
	for (int i=1;i<=n;i++){
		fill(pos+1,pos+m+1,0);
		int top=0;
		for (int j=i;j<=n;j++){
			if (!pos[a[j]]) q[++top]=a[j],pos[a[j]]=top;
			else{
				for (int k=pos[a[j]]+1;k<=top;k++) pos[q[k]]=0;
				top=pos[a[j]],pos[a[j]]=top;
			}
		}
		for (int j=1;j<=top;j++) ans[q[j]]++;
	}
	for (int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
} 
