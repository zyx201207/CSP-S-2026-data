#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p,k;
int s[500010];
int map[8010][8010];
int output(int qi,int zhong){
	int sum=0;
	sum+=s[q1]+s[zhong];
	
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>s[i];
	}
	memset(0,vis,sizeof(vis));
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			int a1,t1;
			cin>>a1>>t1;
			if(j==1){
				
			}else if(j==k){
				
			}else{
				
			}
		}
	}
	while(p--){
		int qi,zhong;
		cin>>qi>>zhong;
		int sum=output(qi,zhong);
		cout<<sum<<endl;
	}
	return 0;
}

