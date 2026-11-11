#include<bits/stdc++.h>
using namespace std;
long long n,a[1000005];
string t,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>t[i];
		ans+=a[i];
	}
	int flag=0;
	for(int i=2;i<=n;i++){
		if(t[i]!=t[i-1]){
			flag=1;
			break;
		}
	}
	if(flag==0){
		cout<<0;
	}else{
		cout<<ans/2;
	}
	
		return 0;
}
