#include <bits/stdc++.h>
using namespace std;
long long a[500005];
long long p[500005];
long long n,m;
int main(){
	p[0]=0;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >>n>> m;
	for(int i =1;i<=n;i++){
		cin >> a[i];
		p[i]=p[i-1]+a[i];
		
	}
	int mx=-1;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		double x=i;
		int now=ceil((p[i]+m)/x);
		if(now>=a[i]){
			if(i>mx){
				mx=i;
			}
		}
	}
	if(mx==-1000000){
		cout <<0<<endl; 
	}
	else{
		cout << mx<<endl;
	}
	
	return 0;
}
