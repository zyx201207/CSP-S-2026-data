#include<bits/stdc++.h>
using namespace std;
long long a[200005]={0},l=0,mm,ans=0,aa,n,aaa=0;
string b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	
	if(n==1){
		cout<<ans;aaa=1;
	}else{
	if(n==2){
		cin>>a[1]>>b[1]>>a[2]>>b[2];
		if(b[1]==b[2]){
			cout<<ans;aaa=1;
		}else{cout<<ans+1;aaa=1;}	
	}else{
		cin>>a[1]>>b[1];
	for(int i=2;i<=n;i++){
		cin>>a[i]>>b[i];
		if(b[i]==b[i-1]){
		a[i-1]+=a[i];i--;
		}
		l+=a[i];
		mm=i;	
	}for(int i=1;i<=mm/2+1;i++){
	
	if(b[i]==b[mm-i+1]){
		if(a[i]>a[mm+1-i]){
	
		aa=a[i]-a[mm+1-i];
		ans+=aa;}else{
			aa=a[mm+1-i]-a[i];
			ans+=aa;
		}
	}else{
		if(a[i]>a[mm+1-i]){
			ans+=a[i];
		}else{ans+=a[mm-i+1];
		}
	}}
	
	
	}if(aaa==0){cout<<ans;
	}
	}	

	return 0;
}
