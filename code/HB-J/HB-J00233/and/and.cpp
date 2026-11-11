#include<bits/stdc++.h>
using namespace std;
struct f{
	int k;
	int idx;
}li[200010];
bool cmp(int x,int y){
	return x>y;
}
bool cmp2(f x,f y){
	return x.k<y.k;
}
int n,m,l=0,ans=0;
int a[200010],b[200010],c[35];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	for(int j=1;j<=30;j++){
		c[j]=pow(2,j);
	}
	for(int i=n;i>=1;i--){
		int mi=0x3f3f3f3f;
		for(int j=1;j<=30;j++){
			if(c[j]>a[i] && c[j]-a[i]<mi){
				mi=c[i]-a[i];
			}
		}
		l++;
		li[l].k=mi,li[l].idx=i;
	}
	sort(li+1,li+l+1,cmp2);
	for(int i=1;i<=m;i++){
		b[i]=a[li[i].idx];
	}
	ans=b[1];
	for(int i=2;i<=m;i++) ans&=b[i];
	printf("%d",ans);
	return 0;
}
