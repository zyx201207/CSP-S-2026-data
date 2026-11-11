#include<bits/stdc++.h>
using namespace std;

long long a[100010],ans=1,ii=2;
long long n=0,m=0;
bool cmp(long long a,long long b){
	return a<b;
}
void so(){
	a[ii-1]+=a[ii]-a[ii-1];
	m-=a[ii]-a[ii-1];
	if(m>=0){
		ans+=1;
	}else{
		return;
	}
	ii++;
	long long c=0;
	for(long long i=ii-1;i>=1;i--){
		c+=a[ii]-a[i];
	}
	if(m>=c){
		so();
	}else{
		return;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	so();
	cout<<ans<<endl;
	return 0;
}
