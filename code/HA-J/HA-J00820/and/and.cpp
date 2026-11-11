#include<bits/stdc++.h>
using namespace std;
const long long N=1073741834;
long long n,m,a[200010],ans,tt;
bool ff[N];
void f(long long x,long long sum){
	if(x==0){
		ans=max(sum,ans);
		return;
	}
	for(int j=1;j<=n;j++){
		if(ff[j]) continue;
		ff[j]=1;
		long long t=sum;
		t&=a[j];
		f(x-1,t);
		ff[j]=0;
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		ff[i]=1;
		f(m-1,a[i]);
		ff[i]=0;
		//cout<<x<<' '<<y<<' ';
	}
	cout<<ans;
	return 0;
}
