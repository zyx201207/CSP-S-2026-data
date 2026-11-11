#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
string s;
int a[100010];
char c[100010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n<=1){
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	if(n==2){
		if(c[1]==c[2]){
			cout<<0<<endl;
			return 0;
		}else{
			if(a[1]>=a[2]){
				cout<<a[2]<<endl;
				return 0;
			}else{
				cout<<a[1]<<endl;
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			if(i==n){
				break;
			}
			if(c[i+1]!=c[i]){
				c[i+1]=c[i];
				ans++;
			}
		}
	}
	if(n%2==0){
		cout<<ans<<endl;
	}else{
		cout<<ans-1<<endl;
	}
	return 0;
} 
