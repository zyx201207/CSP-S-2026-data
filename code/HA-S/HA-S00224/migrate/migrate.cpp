#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int MAXN=200006;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t,c;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		int a[MAXN];
		int ans=0;
		for(int j=1;j<=n;j++){
			cin>>a[i];
		}
		for(int j=1;j+3<=n;j++){
			if(a[j+3]-a[j]<=2*d){
				ans++;
			}
			else{
				cout<<ans;
				continue;
			}
		}
		cout<<ans;
		if(i<t){
		cout<<endl;		
		}
	}
	
	return 0;
}
