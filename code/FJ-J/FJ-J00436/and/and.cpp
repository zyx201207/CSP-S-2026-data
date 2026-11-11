#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
int n,m,ans=0x3f3f3f3f;
int a[200005];
int h1(int x){
	if(x==0)return 0;
	for(int i=0;i<=32;i++){
		if(((1<<i)<=x&&1<<(i+1)>=x)||(1<<i)==x){
			return i;
		}
	}
}
bool cmp(int a,int b){
	if(h1(a)!=h1(b))return h1(a)>h1(b);
	else return a>b;
}
signed main(){
	//int t1,t2;cin>>t1>>t2;
	//cout<<cmp(t1,t2);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++)ans&=a[i],cout<<a[i]<<' ';cout<<endl; 
	cout<<ans;
	return 0;
}
