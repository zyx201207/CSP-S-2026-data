#include<bits/stdc++.h>
using namespace std;
long long a[200005]={};
long long n,ans=0,cnt=0;
string b,h,h1;
bool f=0,f1=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		cnt+=a[i];
		if(b[i]!=b[i-1]){
			f1=0;
		}
	}
	if(f1==1){
		cout<<0;
		return 0;
	}
	
	long long k=1;
	
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=a[i];j++){
			h1[k]=b[i];
			k++;
//			cout<<h1[k];
//			if(k>=cnt/2){
//				f=1;
//				break;
//
//			}
		}
//		if(f==1) break; 
	}
	
	f=0;
	k=1;
	
	for(long long i=n;i>=1;i--){
		for(long long j=1;j<=a[i];j++){
			h[k]=b[i];
			k++;
//			cout<<h[k];
//			if(k>=cnt/2){
//				f=1;
//				break;
//			}
		}
//		if(f==1) break; 
	}

	for(long long i=1;i<=k;i++){
		if(h[i]!=h1[i]){
			ans++;
		}
	}
	cout<<ans/2;
	return 0;
}
