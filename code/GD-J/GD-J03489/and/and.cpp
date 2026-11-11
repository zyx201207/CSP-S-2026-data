#include<bits/stdc++.h>
using namespace std;
long long n,m;
unsigned long long a[210000];
unsigned long long f(unsigned long long s){
	unsigned long long res=0;
	while(s){
		if(s&1){
			res++;
		}
		s>>=1;
	}
	return res;
}
bool cmp(unsigned long long a,unsigned long long b){
	return f(a)>f(b);
}
bool cmp2(unsigned long long a,unsigned long long b){
	return a>b;
}
unsigned long long ans;
unsigned long long ans2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(int i=2;i<=m;i++){
		ans&=a[i];
	}
	sort(a+1,a+n+1,cmp2);
	ans2=a[1];
	for(int i=2;i<=m;i++){
		ans2&=a[i];
	}
	cout<<max(ans,ans2); 
	return 0;
}
