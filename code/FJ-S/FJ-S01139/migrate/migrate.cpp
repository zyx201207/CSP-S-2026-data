#include<bits/stdc++.h>
using namespace std;
long long n,c,t,m,a[5010100],s,b[5010100],o,v;
int main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b[i]=b[i-1]+a[i];
		}
		if(c==11||c==12){
			if(a[2]-a[1]<m){
				cout<<n-(int(m/(a[2]-a[1]))*2-1)<<endl;
			}
			else cout<<"0"<<endl;
		}
	}
	return 0;
} 
