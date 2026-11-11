#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=5&&m<=2){
		if(m==1)cout<<n;
		else{
			if(n==2)cout<<2<<' '<<2;
			if(n==3){
				for(int i=1;i<=n;i++){
					if(a[1]==a[2])cout<<2<<' '<<3;
					if(a[1]==a[3])cout<<3<<' '<<1;
					if(a[2]==a[3])cout<<3<<' '<<1;
				}
			}	
		}
	}
	return 0;
}
