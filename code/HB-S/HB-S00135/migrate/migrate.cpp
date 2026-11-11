#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,ans;
int x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >>c>>t;
	while(t--){
		cin >>n>>d;
		if(n<=2){
			cout <<0<<endl;
			break;
		}
		int sum=1; 
		cin >>x[1]>>x[2];
		int s=x[2]-x[1];
		for(int i=3;i<=n;i++){
			cin >>x[i];
			int s2=x[i]-x[i-1];
			if(s==s2){
				sum++;
			}
			else{
				s=s2;
				if(sum>2){
					ans+=sum-2;
				}
				sum=0;
			}
		}
		if(sum>2){
			ans+=sum-2;
		}
		cout <<ans<<endl;
	}
}
