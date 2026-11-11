#include <bits/stdc++.h>
using namespace std;
long long x[2000005];
int n,d;
bool check(int i,int j){
	if((j-i+1)%2==0&&x[j]-x[i]<=d)
	return 1;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	for(int e=1;e<=t;e++){
		
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		long long cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(check(i,j)){
					cnt++;
				}
			}
		}
		cout<<cnt/n<<"\n";
	}
	
	return 0;
} 
