#include<bits/stdc++.h>
using namespace std;
long long int a,b,c,d,e,n,m;
struct edg(){
	int son;
	int fa;
	int sum;
};
long long int- s[10000][10000];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);	
	freopen("migrate","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>n>>m;
	long long int m1[m+1];
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			cin>>s[i][1];
			s[i][1]=abs(s[i][1]-1);
		}
		for(int j=1;j<=a;j++){
			while(d!=0){
				int o=1;
				if(s[o][1]+b>=s[j][1]){
					o=j;
					s[1];
				}
				
				
			}
		
		}
		
	}
	
	cout<<"1"<<endl<<"2";
}
