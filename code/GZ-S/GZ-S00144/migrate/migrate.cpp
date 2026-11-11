//GZ-S00144 贵阳市南明区李端棻中学 周熙沅
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int q=0;q<t;q++){
        int n,d,cnt=0;
        cin>>n>>d;
		int x[n+5];
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		if((x[n]-x[0])%d!=0){
			cnt=1;
		}else if((x[n]-x[0])%d==0){
			cnt=2;
		}else{
			cnt=0;
		}
	}
	return 0;
}
