#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+5;
long long n,m,a[N],ma=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1,greater<long long>());
		ma=a[1];
		cout<<ma;
		return 0;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				long long an_d=(a[i] & a[j]);
				ma=max(ma,an_d);
			}
		}
		cout<<ma;
		return 0;
	}else{
		sort(a+1,a+n+1,greater<long long>());
		ma=a[1];
		for(int i=2;i<=m;i++){
			ma=(ma & a[i]);
		}
		cout<<ma;
		return 0;
	}
	return 0;
}
