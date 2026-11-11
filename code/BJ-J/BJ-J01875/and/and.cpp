#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans;
string s[200010],c="111111111111111111111111111111111";
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a,a+n);
		cout<<a[0];
		return 0;
	}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		long long k=1;
		for(int j=0;j<32;j++){
			k*=2;
		}
		for(int j=0;j<=32;j++){
			if(a[i]>=k){
				s[i]+='1';
				a[i]-=k;
				k/=2;
			}else{
				s[i]+='0';
				k/=2;
			}
		}
	}
	for(int i=n-1;i>n-m-1;i--){
		for(int j=0;j<=32;j++){
			if(s[i][j]=='1'&&c[j]=='1') c[j]='1';
			else c[j]='0';
		}
	}
	long long k=1;
	for(int j=0;j<32;j++){
		k*=2;
	}
	for(int i=0;i<=32;i++){
		if(c[i]=='1'){
			ans+=k;
			k/=2;
		}else k/=2;
	}
	cout<<ans;
	return 0;
}
