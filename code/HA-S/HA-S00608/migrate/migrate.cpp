#include<bits/stdc++.h>
using namespace std;
long long t,n,d,x[2000010],ans[100010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>t;
	while(t--){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		for(int i=0;i<n;i++){
			int a=abs(x[i]-x[i+2]);
			if(a<=d){
				ans[t]++;
				i++;	
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
