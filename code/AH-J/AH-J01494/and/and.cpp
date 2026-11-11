#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200001],s=0;
long long pd(long long a,long long b){
	int S=1,s=0;
	if(a==b){
		return a;
	}
	while(1){
		if(a==0||b==0){
			break;
		}
		if(a%2==1&&b%2==1){
			s+=S;
		}
		a/=2;
		b/=2;
		S*=2;
	}
	return s;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i+1;j<=n;j++){
			s=max(s,pd(a[i],a[j]));
		}
	}
	cout<<s;
	return 0;
}
