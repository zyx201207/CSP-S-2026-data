#include<bits/stdc++.h>
using namespace std;
long long n,m;
struct sz{
	long long a10;
	string s;
}a[200005];
string to10_2(long long a){
	string s="";
	while(a>0){
		s=char(a%2+'0')+s;
		a/=2;
	}
	return s;
}
bool cmp(sz x,sz y){
	long long w1=x.s.size(),w2=y.s.size();
	if(w1!=w2){
		return w1>w2;
	}
	long long xx1=0,yy1=0,j=0;
	for(long long i=0;i<w1;i++){
		if(x.s[i]=='1'){
			xx1++;
		}
		if(y.s[i]=='1'){
			yy1++;
		}
	}
	if(xx1!=yy1){
		return xx1>yy1;
	}
	return x.a10>y.a10;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].a10;
		a[i].s=to10_2(a[i].a10);
	}
	sort(a+1,a+n+1,cmp);
	long long ans=a[1].a10;
	for(int i=2;i<=m;i++){
		ans&=a[i].a10;
	}
	cout<<ans;
	return 0;
}
