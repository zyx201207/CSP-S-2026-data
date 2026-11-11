#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,i,ans;
long long a[500001];
bool cmp(long long x,long long y){
	if(x>y) return true;
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=0;i<n;++i) cin>>a[i];
	sort(a,a+n,cmp);
	for(i=1;i<n;++i)
		if((a[0]-a[i])<=m){
			a[i]=a[0];
			m-=(a[0]-a[i]);
		}else{
			a[i]+=m;
			break;
		}
	for(i=0;i<n;++i)
		if(a[i]==a[0])
			++ans;
	cout<<ans<<endl;
	return 0;
}
