#include<bits/stdc++.h>
using namespace std;
int n;
long long a[100000];
char c[100000];
int ans=0;
int sum=0;
int i;
int mx,mn;
long long al;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	sum=a[1];
	for(i=1;i<=n;i++){
		int j=n-i+1;
		if(sum==0)sum=a[i];
		if(sum>=a[j]){
			mx=sum;
			mn=a[j];
		}else{
			mx=a[j];
			mn=sum;
		}
		if(i>j){
			break;
		}
		if(sum==a[j]&&c[i]==c[j]){
			continue;
		}
		if(sum==a[j]){
			ans+=a[i];
		}else if(c[i]==c[j]){
			sum=mx-mn;
		}else {
			ans+=mn;
			sum-=mn;
		}
		
	}
	cout<<ans;
	return 0;
}