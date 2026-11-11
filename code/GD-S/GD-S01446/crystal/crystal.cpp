#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,maxx,a[510000],cha[510000],nee=1;
bool check(int x,int y){
	ll sum=0;
	for(int i=x;i<y;i++){
		sum+=a[y]-a[i];
	}
	return sum<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int flag=1;
	for(int i=2;i<n;i++){
		if(a[i]-a[i-1]!= a[i+1]-a[i]) flag=0;
	}
	if(flag){
		nee=a[2]-a[1];
		for(int i=1;i<=n;i++){
			maxx+=i*nee;
			if(maxx>m){
				cout<<i;
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+maxx;j<=n;j++){
			if(check(i,j)){
				maxx=max(maxx,1ll*(j-i+1));
			}else{
				break;
			}
			
		}
	}
	cout<<maxx;
	return 0;
}

