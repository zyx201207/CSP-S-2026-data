#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10,maxm=3e5+10;
int N,M,a[maxn],b[maxn],c[maxm],l[maxn],incs[maxm];
bool inc[maxm];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&N,&M);
	memset(b,0,sizeof(b));//下一个同号 
	memset(c,0,sizeof(c));//目前最后一个同号
	memset(inc,0,sizeof(inc));//i号是否在场
	memset(l,0,sizeof(l));//目前状态:0在场，>0被...移走（前） 
	memset(incs,0,sizeof(incs));//i号在场?回合 
	for(int i=1;i<=N;i++){
		scanf("%d",&a[i]);
		if (c[a[i]]!=0)
			b[c[a[i]]]=i;
		c[a[i]]=i;
	}
	int pm=0,F=0;
	for(int i=1;i<=N;i++){
		if (i<pm){
			l[i]=F;
			continue;
		}
		F=i,pm=b[i];
		if (b[i]!=0)
			l[i]=i;
		inc[a[i]]=1;
	}
	for(int i=1;i<=N;i++){//第i+1回合,去掉i 
		for(int j=i;j<=N;){
			if (c[a[j]]==j)
				incs[a[j]]++,j++;
			else
				j=c[a[j]];
		}
	}
	for(int i=1;i<=M;i++)
		printf("%d ",incs[i]);
	return 0;
}
