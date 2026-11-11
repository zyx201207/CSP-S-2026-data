#include<bits/stdc++.h>
using namespace std;
int m,n,c,t,d,flag,ans;
const int N=2e6+2;
int x[N];
int s[N];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			s[i]=x[i]+s[i-1];
			if(x[i]-x[i-1]==x[i-1]-x[i-2]) flag=1;
		}
		if(flag){
			for(int i=d+1;i<=n;i++){
				for(int j=1;j<i;j++){
					if((i-j)%d!=0){
						ans++;
					}	
				}
			}
		}
		if(n%2==1&&ans>=2) cout<<0<<endl;
		cout<<ans<<endl;
		
	}	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
