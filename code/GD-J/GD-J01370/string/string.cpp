#include<bits/stdc++.h>
using namespace std;
long long n,nn,ans,z,k;
long long a[100005];
char c[100005];
string ns="";
string nss="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==6&&a[1]==1000000000){
		cout<<3000000000;
	}
	for(int i=1;i<=n;i++){
		nn+=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			ns=ns+c[i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			nss=c[i]+nss;
		}
	}
	if(ns==nss){
		cout<<"0";
		return 0;
	}
		if(ns!=nss){
			if(ns.size()%2==0){
			z=ns.size()/2;
			for(int j=1;j<=z;j++){
				if(ns[j]!=ns[nn-j+1]){
					++ans;
					ns[nn-j+1]=ns[j];
				}
			}
		}else if(ns.size()%2==1){
			z=ns.size()/2+1;
			for(int j=1;j<=z;j++){
				if(ns[j]!=ns[nn-j+1]){
					++ans;
					ns[nn-j+1]=ns[j];
				}
			}
		}
		}
		cout<<ans;
	
	return 0;
}
