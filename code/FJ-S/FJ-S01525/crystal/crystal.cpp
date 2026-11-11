#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=0;
long long a[100005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i = 1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long t = 0;
	if(n%2==0){
		t=n/2;
	}else{
		t=n/2+1;
	}
	long long h = 0;
	for(long long i = 1;i<t;i++){
		h += a[t]-a[i];
	}
	long long t2 = t;
	for(long long i = t+1;i<=n;i++){
		if(a[i]==a[t]){
			t2+=1;
		}
	}
	if(h==m){
		cout<<t2;
	}
	return 0;
} 
