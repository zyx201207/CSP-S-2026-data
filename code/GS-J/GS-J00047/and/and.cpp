#include<bits/stdc++.h>
using namespace std;
long long a[300500];
long long s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}else if(m==n){
		s = a[1];
		for(long long i = 2;i<=n;i++) s = s&a[i];
		cout<<s;
		return 0;
	}else if(m==2){
		for(long long i = 1;i<=n;i++){
			for(long long j = i+1;j<=n;j++){
				s = max(s,a[i]&a[j]);
			}
		}
		cout<<s;
		return 0;
	}else if(m==n-1){
		long long l = 0;
		for(long long i = 1;i<=n;i++){
			for(long long j = 1;j<=n;j++){
				if(i==j) continue;
				if(j==2&&i==j || j==1) l = a[j];
				else l = l&a[j];
			}
			s = max(s,l);
		}
		cout<<s;
		return 0;
	}
	for(int i = 1;i<=n;i++){
		for(int j = i+1;j<=n;j++){
			if(a[i]==a[j]){
				cout<<a[i];
				return 0;
			}
		}
	}
	if(n%2==0) cout<<a[n/2];
	else cout<<a[n/2+1];
	return 0;
}
