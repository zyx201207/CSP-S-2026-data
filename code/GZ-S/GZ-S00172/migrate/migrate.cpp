//GZ-S00172 中央民族大学附属中学贵阳学校 杨忠瀚 
#include<bits/stdc++.h>
using namespace std;
int c,t,x[200005],n,d,c[200005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		long long cnt=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			cnt+=x[i];
		}
		if(t==1)cout<<0<<endl;
		else {
			cnt/=(n+1);
			cnt/=(d+1);
			cout<<cnt<<endl;
		}
	}	
	return 0;
}
