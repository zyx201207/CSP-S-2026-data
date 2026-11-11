#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,ans=0;
long long m,a[500001];
int main(){
	freopen("crystal.in","r",stdin);
	/*提交前记得取消注释freopen*/
	freopen("crystal.out","w",stdout);
	scanf("%d %lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	long long goal=a[2]-a[1];
	if(goal==0)goal=1;
	ans=m/goal/2+1;
	printf("%d\n",ans);
	return 0;

}
