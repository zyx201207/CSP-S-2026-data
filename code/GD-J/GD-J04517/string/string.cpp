#include<iostream>
using namespace std;
const int N = 2e5+10;
long long maxx(long long x,long long y){
	if(x>=y) return x;
	return y;
}long long minn(long long x,long long y){
	if(x<=y) return x;
	return y;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,s1[N]={},s2[N]={};
	string s="";
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		s1[i]=s1[i-1]+a;
		s+=c;
	}
	for(int i=1;i<=n;i++){
		s2[i] = s1[n]-s1[n-i];
	}
	int i1=1,i2=1;
	long long sum=0;
	while(i1<=n && i2<=n){
		if(i1>i2) swap(i1,i2);
		long long mn=minn(s1[i1],s2[i2]),mx=maxx(s1[i1-1],s2[i2-1]);
		long long cnt=maxx(0,mx-mn);
		if(s[i1-1]!=s[n-i2]) sum+=cnt;
		i1++;
	}cout<<sum;
	return 0;
} 
