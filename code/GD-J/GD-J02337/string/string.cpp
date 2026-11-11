#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10 ; 
string c[N];
int a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string c1,s1,c2,s2;
	int n;
	cin>>n;
	int k=n/2;
	for(int i=1;i<=n;i++){
		
		cin>>a[i]>>c[i];
	}
	int r=n,i=1,ans=0;
	while(i<=r){
		if(c[r]!=c[i]){
			if(a[i]>=a[r]){
				ans+=a[r];
				a[i]-=a[r];
				r--;
			}
			else{
				ans+=a[i];
				a[r]-=a[i];
				i++;
			}
		}else{
			if(a[i]>=a[r]){
				a[i]-=a[r];
				r--;
			}
			else{
				a[r]-=a[i];
				i++;
			}
		}
		if(a[i]==0)i++;
		if(a[r]==0)r--;
	}	
	cout<<ans;
	return 0;
	
} 
