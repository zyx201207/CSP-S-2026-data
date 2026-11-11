#include<bits/stdc++.h>
using namespace std;
long long a[500001],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long zhong=a[(n+1)/2];
	for(int i=(n+1)/2;i>=1;i--){
		m-=(zhong-a[i]);
		if(m<0){
			break;
		}
		ans++;
	}
	for(int i=(n+1)/2+1;i<=n;i++){
		if(a[i]==zhong){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
