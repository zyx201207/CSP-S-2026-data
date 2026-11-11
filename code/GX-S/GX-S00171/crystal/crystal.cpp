#include<bits/stdc++.h>
using namespace std;
long long a[5000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long maxx=0;
	
	long long tp;
	for(int i=1;i<=n;i++){
		tp = max(maxx,a[i]-a[i-1]);
	}
	if(tp == 1){
		long long q=0;
		while(m-q>0){
			q++;
			m-=q;
		}
		if(q>n){
			cout<<n;
		}else{		
			cout<<q+1;
		}	
		return 0;
	}
	
	long long p,ans=0;
	if(a[1] >= 0)p=a[1];
	else p=-a[1];
	for(int i=1;i<=n;i++){
		long long x = a[i+1]-a[i];
		if(m-p<0){
			cout<<ans;
			return 0;
		}
		if(x>=0)p+=x;
		else p+=-x;
		ans++;
	}
	cout<<n;
	return 0;
}
