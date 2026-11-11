#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[500001];
int b1[300001];
int p[300001];
int ans[300001];
int flag[300001];
int flag1[300001];
bool flag2=0;
int pp[300001];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]<a[i-1])
			flag2=1;
		b1[a[i]]=i;
		p[a[i]]++;
	}
	if(!flag2){
		for(int i=1;i<=m;i++)
			pp[i]=pp[i-1]+p[i];
		for(int i=1;i<=m;i++){
			if(p[i]%2==1)
				printf("%d ",pp[i-1]+p[i]/2+1);
			else
				printf("%d ",p[i]/2);
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		p[a[i-1]]--;
		int now=i;
		while(now<=n){
			while(b1[a[now]]==now){
				ans[a[now]]++;
				now++;
			}
			while(now<=n){
				if(b1[a[now]]==now){
					ans[a[now]]++;
					now++;
					continue;
				}
				now=b1[a[now]];
			}
		}
	}
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
	return 0;
}
