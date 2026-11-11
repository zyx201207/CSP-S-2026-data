#include<bits/stdc++.h>
using namespace std;
const int N=200005;
#define int long long
int a[N];
char c[N];
signed main(){
	   freopen("string.in","r",stdin);
	   freopen("string.out","w",stdout);
	   ios::sync_with_stdio(false);
	   cin.tie(NULL);
	   int n,ans=0;
	   cin>>n;
	   for(int i=1;i<=n;i++){
	   	cin>>a[i]>>c[i];
	   	if(c[i-1]!=c[i]){
	   		ans++;
		   }
	   }
	   if(ans==1){
	   	cout<<0;
	   	return 0;
	   } else{
	   	ans--;
	   	int SB=n/2+1;
	   	for(int i=SB;i<=n;i++){
	   		ans+=a[i];
		   }
	   }
	   cout<<ans;
	   
	   return 0;
}


