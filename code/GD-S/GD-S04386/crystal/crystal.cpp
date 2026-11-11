#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],pj,ans=1;
bool cmp(long long x,long long y){
	return abs(pj-x)<abs(pj-y);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pj+=a[i];
	}
	pj/=n;
	sort(a+1,a+1+n,cmp);
	pj=a[1];
	for(int i=2;i<=n;i++){
		if(m>=abs(pj-a[i])){
			ans++;
			m=m-abs(pj-a[i]);
		}
		else{
			cout<<ans;
			return 0;
		}
	}
	cout<<ans;
	return 0;
}
