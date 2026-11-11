#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5;
int n,a[28],sum=0,num=0,ac[N+5];
char c[28],v[N+5];
inline void tle(){
	for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				v[num+j]=c[i];
			}
		}
		int csp=1;
		for(int i=num/2;i>=1;i--){
			if(v[i]!=v[i+csp]) sum++;
			csp+=2;
		}
		cout<<sum;
}
/*inline pac(){
	for(int i=2;i<=n;i++){
		ac[i]=ac[i-1] 
	}
}*/
signed main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		num+=a[i];
	}
	if(n<=INT_MAX){
		tle();
	}/*else pac();*/
	
	return 0;
}
//... --- ...
