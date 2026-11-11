#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010],s,ans=0,aas=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	s=a[n/2+1];
	for(int i=1;i<=n;i++){
		b[i]=abs(s-a[i]);
	}
	sort(b+1,b+n+1);
	for(int i=2;i<=n;i++){
		ans+=b[i];
		if(ans<=m){
			aas++;
		}
	}
	cout<<aas;
	return 0;
}
