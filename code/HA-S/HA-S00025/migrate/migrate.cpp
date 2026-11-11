#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,j;
const int N=100005;
int shuzu[N];

int main(){
freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	int ans[t];
	for(int i=1;i<=t;++i){
		cin>>n>>d;
		for( j=1;j<=n;++j)	cin>>shuzu[j];
		
		if(shuzu[n]==2) cout<<0<<endl;
		else ans[i]=shuzu[n]%2+1;

	}
for(int i=1;i<=t;++i) cout<<ans[i]<<endl;
fclose(stdin);
fclose(stdout);
return 0;	
} 
