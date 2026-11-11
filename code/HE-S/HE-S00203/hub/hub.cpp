#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TOOHARDQWQ return 0;
int n,d;
int a[2200000];
int f(int t,int z){
	if(t==z){
		return 1;
	}else if(t>z){
		return 0;
	}else{
		int cnt=0;
		for(int i=1;i<=d;i++){
			cnt+=f(t+1,i);
		}
		return cnt; 
	}
}
signed main(){
		freopen("migrate.in","r",stdin);
		freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			
			cin>>n>>d;
			
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			int cnt=0;
			for(int i=1;i<=n;i++){
				for(int j=2;j<=n;j++){
					cout<<f(i,j)<<endl;
					if(f(i,j)==2){
						cnt++;
					}else if(f(i,j)>2){
						break;
					}
				}
			}
			
		}
	}
	TOOHARDQWQ
} 
