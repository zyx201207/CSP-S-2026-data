#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long a[1000000005];
	char c[1000000005];
	long long ans;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
    }
	if(n==1){
		cout<<0<<endl;
	}
	if(n==2){
		if(c[1]==c[2]){
			cout<<0<<endl;
		}else{
			if(a[1]%2==0){
				ans=a[1]/2;
			}
			if(a[2]%2==0){
				ans=a[2]/2;
			}
			cout<<ans<<endl;
		}
			
			
	}
	return 0;
}
