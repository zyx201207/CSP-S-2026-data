#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n; 
int a[N];
char c[N];
int ans;
bool flag=true;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=2;i<=n;i++){
		if(c[i]!=c[i-1]) flag=false;
	}
	if(flag==true){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(c[i]==c[n+1-i]){
			if(a[i]==a[n+1-i]) continue;
			else{
				ans+=abs(a[i]-a[n+1-i]);
				a[n+1-i]=a[i];
				if(a[i]>a[n+1-i]){
					a[n+1-i-1]-=a[i]-a[n+1-i];
				}
				else{
					a[n+1-i-1]+=a[n+1-i]-a[i];
				}
			} 
		}
		else
		{
			a[n+1-i]=a[i];
			c[n+1-i]=c[i];
			ans+=a[i];
		}
	}
	cout<<ans;
	return 0;
}

