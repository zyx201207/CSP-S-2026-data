#include<bits/stdc++.h>
using namespace std;
long long n,a[1000000001],m,b[1000000001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int c=1;c<=n;c++){
		cin>>a[c];
	}
	
	for(int i=2;i<=n;i++){
		int o=0;
		int m1=m;
		for(int j=i-1;j>=1;j--){
			if(m1>=a[i]-a[j]){
				o+=a[i]-a[j];
				m1-=a[i]-a[j];
				b[i]++;
			}
	    }
	}
	long long e=0;
	for(int c=1;c<=n;c++){
		//cout<<b[c]<<" "<<endl;
		e=max(e,b[c]);
	}
	cout<<e+1;
	return 0;
} 
