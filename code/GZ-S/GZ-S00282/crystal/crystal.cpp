//王明伟 GZ-S00282  遵义一中 
#include<bits/stdc++.h>
using namespace std;
int m,n,ans=0,b,v;
int main(){
cin>>m>>n;
int a[m];
v=n;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	sort(a,a+m);
	for(int i=0;i<m;i++){
		for(int j=i;j>=0;j--){
			if((a[i]-a[j])<=n){
			b++;
			n=n-a[i]+a[j];
			}
		}
		if(b>=ans){
			ans=b;
		}
			b=0;
			n=v;
	}
    cout<<ans;
	return 0;
}
