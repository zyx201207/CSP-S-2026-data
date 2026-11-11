#include<bits/stdc++.h>
#define MAXN 200005
using namespace std;
bool cmp(int x,int y){
	return x>y?1:0;
}
int a[MAXN];
int b[40];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	b[0]=1;
	for(int i=1;i<=35;i++)b[i]=b[i-1]*2;
	//初始化乘方数组 
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	//输入 
	sort(a+1,a+n+1,cmp);
	int f;
	for(int i=1;i<=35;i++)if(b[i]<=a[m]&&a[m]<b[i+1])f=i;
	for(int i=1;i<=n;i++)a[i]%=b[f+1];
	sort(a+1,a+n+1,cmp);
	//过滤多余位
	while(f>0){
		if(a[m]<b[f]){
			f--;
			for(int i=1;i<=n;i++)a[i]%=b[f+1];
			sort(a+1,a+n+1,cmp);
		}
		else break;
	}
	//寻找合适位 
	int ans=a[1];
	for(int i=1;i<=m;i++)ans=(ans&a[i]);
	printf("%d",ans);
	return 0;
} 
