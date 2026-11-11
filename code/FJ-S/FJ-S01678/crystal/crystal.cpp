#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long cha=0,a,b;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(i==1){
			b=a;
		}else if(i==2){
			cha=a-b;
		}
	}
	cha=abs(cha);
	for(int i=1;i<n;i++){
		int num=(cha+cha*i)*i/2;
		if(num>m){
			cout<<i;
			return 0;
		}
	}
	cout<<n;
	return 0;
} 
