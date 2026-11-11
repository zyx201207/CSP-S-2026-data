#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[10000005];
char s[10000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,t=1;
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>c[i];
		int j=1;
    	for(;j<=a[i];j++){
		    s[t]=c[i];
		    t++;
		}
		
	}
	
	int l=t-1,ans=0;
	for(int i=1;i<=t-1;i++){
		if(s[l]-s[i]<0) break;
		if(s[l]!=s[i]) ans++;
        l--;
	}
	cout<<ans;
	
	return 0;
	
}
	

