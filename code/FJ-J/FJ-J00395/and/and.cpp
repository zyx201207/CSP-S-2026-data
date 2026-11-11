#include<iostream>
#include<algorithm>
using namespace std;
int n,m,ans,num;
int x[50],y[50];
struct ckll{
	int aa;
	int bb;
}a[200005];
bool cmp(ckll a,ckll b){
	if(a.bb!=b.bb){
		return a.bb>b.bb;
	}else{
		a.aa>b.aa;
	}
}
bool cmp1(ckll a,ckll b){
	return a.aa>b.aa;
}
void ckl(int a){
	for(int i=1;a>0;i++){
		x[i]=a%2;
		a/=2;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		num=0;
		scanf("%d",&a[i].aa);
		ckl(a[i].aa);
		for(int j=1;j<=31;j++){
			num+=x[j];
		}
		a[i].bb=num;
	}
	if(m==1){
		sort(a+1,a+n+1,cmp1);
		printf("%d",a[1].aa);
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	ckl(a[1].aa);
	for(int i=1;i<=31;i++){
		y[i]=x[i];
	}
	for(int i=2;i<=m;i++){
		for(int j=1;j<=31;j++){
			x[j]=0;
		}
		ckl(a[i].aa);
		for(int j=1;j<=31;j++){
			if(y[j]!=x[j]){
				y[j]=0;
			}
		}
	}
	int p=1;
	for(int i=1;i<=31;i++){
		if(y[i]==1){
			ans+=p;
		}
		p*=2;
	}
	printf("%d",ans);
	return 0;
}
