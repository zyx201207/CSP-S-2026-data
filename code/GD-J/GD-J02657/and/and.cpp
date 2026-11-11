#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200000+5;
const int F=0xffffffff;
struct B{
	int num;
	int a[35];
};
int n,m,a[N],c[N],p,maxp,t;
B b[N],ans,cnt;
bool cmp(int a,int b){
	return a>=b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		p=0;
		b[i].num=a[i];
		while(a[i]){
			b[i].a[p]=a[i]&1;
			a[i]=a[i]>>1;
			p++;
		}
		c[i]=p;
	}
//	for(int i=1;i<=n;i++){
//		for(int j=8;j>=0;j--){
//			cout<<b[i].a[j];
//		}cout<<endl;
//	}
	p=c[1];
	for(int i=0;i<p;i++)ans.a[i]=F;
	for(int i=0;i<p;i++){
		for(int j=1;j<=n;j++){
			if(b[j].a[i]){
				ans.a[i]&=b[j].num;
				cnt.a[i]++;
			}
			if(cnt.a[i]==m&&ans.a[i]!=F){
				cout<<ans.a[i];
				break;
			}
		}
	}
	return 0;
}
