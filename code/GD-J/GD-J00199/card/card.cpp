#include<bits/stdc++.h>
using namespace std;
long long n,m,b[500003],x=0,dis[500003],cnt,q=1,d=0,c[500002]={0};
 long long k=0,g=0,f;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
		ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;if(m==1){cout<<n;return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];if(b[i]==b[i+1]){
	q++;
		}
	} 
if(q==n){cout<<n;return 0;
}
	
	for(int i=1;i<=n;i++){
		
	c[i]=i;
	}
	for(int i=1;i<=n;i++){
		cout<<c[i];
	}
	return 0;
}
