#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,ans;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
const int N=10000+5;
int feishu[N];
int ans[N];
	for(int i=1;i<=t;++i){
		cin>>n>>k;
		for(int j=1;j<=2*n-2;++j)
		cin>>feishu[j];
		if(n%k==0) cout<<1<<endl;
		else ans[i]=n/k-1;
	}
for(int i=1;i<=t;++i) cout<<ans[i]<<endl;
fclose(stdin);
fclose(stdout);
return 0;
} 
