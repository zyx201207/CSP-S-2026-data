#include <iostream>
#include <algorithm>
using namespace std;
struct S{
	int a;
	bool f;
}a[200005];
int cmpn;
bool cmp(S a,S b){
	if(a.f!=b.f) return a.f>b.f;
	int ax=a.a&(1<<cmpn),bx=b.a&(1<<cmpn);
	return ax>bx;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i].a);
		a[i].f=1;
	}
	int ans=0;
	sort(a+1,a+1+n,[](S a,S b){return a.a>b.a;});
	for(int j=30;j>=0;j--){
		cmpn=j;
		sort(a+1,a+1+n,cmp);
		int f=0;
		if(a[1].a&(1<<j)){
			f=1;
			for(int i=1;i<=n;i++){
				if(a[i].f==0){
					if(i<=m) f=0;
					break;
				}
				if((a[i].a&(1<<j))==0){
					if(i<=m) f=0;
					if(f==1) a[i].f=0;
				}
			}
		}
		if(f) ans+=(1<<j);
	}
	cout<<ans;
	return 0;
}
// J01443 OrangeSheep
