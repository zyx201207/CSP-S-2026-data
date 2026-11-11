#include<bits/stdc++.h>
using namespace std;

int s[100005];
int num[100005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,ans=0;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>s[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=n;j>=i;j--){
				if(abs(s[j]-s[i])>d){
					ans++;
				}
			}
		}
		cout<<ans;
	}
	
	return 0;
}
