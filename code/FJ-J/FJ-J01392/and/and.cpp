#include <bits/stdc++.h>
using namespace std;

long long n,m;
long long a[200005],s[200005];
int i;

void f(int x){
	int c=1;
	while(x>0){
		s[i]+=x%2*c;
		x/=2;
		c*=10;
	}
	return;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		f(a[i]);
	}
	long long ans=0;
	if(m==n){
		ans=s[1];
		for(int l=2;l<=n;l++){
			ans+=ans&s[l];
		}
		cout<<ans;
		return 0;
	}
	for(int l=1;l<=n-m+1;l++){
		for(int r=l+1;r<=n;r++){
			ans=max(s[l]&s[r],ans);
		}
	} 
	int num=0,c=1;
	while(ans>0){
		num+=ans%10*c;
		ans/=10;
		c*=2;
	} 
	cout<<num;
	return 0; 
}
