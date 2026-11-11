/*
*/
#include<bits/stdc++.h>
using namespace std;
long long n,m,ans;
struct st{
	long long x,y;
}a[212345];
int f(long long x){
	long long sum=0;
	while(x){
		if(x%2==1) sum++;
		x/=2;
	}return sum;
}
int main(){
	freopen("and5.in","r",stdin);
	freopen("and5.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		a[i].y=f(a[i].x);
	}sort(a+1,a+1+n,[](st a,st b){
		if(a.y!=b.y) return a.y>b.y;
		return a.x>b.x;
	});
	ans=a[1].x;
	for(int i=2;i<=m;i++){
		ans&=a[i].x;
	}cout<<ans;
	return 0;
} 
