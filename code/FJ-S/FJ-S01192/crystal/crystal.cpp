#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[5000011];
long long mi[500011];
long long s,num,ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<n;i++){
		mi[i]=a[i+1]-a[i];
	}
	sort(mi,mi+n);
	for(long long i=1;i<n;i++){
		if(a[i]==0){
			ans++;
			continue;
		}
		else{
			num++;
		}
		if(m>0){
			m=m-num*mi[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
