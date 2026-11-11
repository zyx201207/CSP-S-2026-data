#include<bits/stdc++.h>
using namespace std;
string a,b[200010];
int n,m;
long long ans,q[200010],k;
int gcd(int x,int y){
	while(y){
		int s=x%y;
		x=y,y=s;
	}return x;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>q[i]>>b[i];
		if(i==1){
			k=q[i];
		}else if(k!=1){
			k=gcd(k,q[i]);
		}
	}
	for(int i=1;i<=n;i++){
		q[i]/=k;
		while(q[i]--){
			a+=b[i]; 
		}
	}
	for(int i=0;i<=a.size()/2-1;i++){
		int h=a.size()-i-1;
		if(a[i]!=a[h]){
			ans++;
		}
	}cout<<ans*k;
	return 0;
} 
