#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t;
long long ans;
long long s[N];
bool flag=0,flag2;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		long long n,d;//n为岛屿数量，d为一次能飞行的最远距离
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>s[i];
		}
		for(int i=1;i<=n-2;i++){
			if(s[i+1]-s[i]==s[i+2]-s[i+1]){
				flag=1;
			}else{
				flag=0;
			}
		}
		if(flag&&n==4&&2*(s[2]-s[1])<=d){
			cout<<1<<endl;
			continue;
		}
		for(int i=1;i+3<=n;i++){
			long long mx=INT_MIN;
			int j=i+3;
			for(int k=i;k<=j-2;k++){
				mx=max(mx,(s[k+2]-s[k]));
				if(s[k+3]-s[k]<=d){
					flag2=1;
				}
				if(s[k+3]-s[k]<0){
					flag2=0;
				}
			}
			if(mx<=d&&!flag2){
				ans++;
			}
			flag2=0;
		}
		cout<<ans<<endl;
		memset(s,0,sizeof(s));
		
	}
	
	
	
	return 0;
} 
