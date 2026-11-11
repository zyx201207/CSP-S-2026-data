#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005],mj[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		int cnt=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			mj[i]=x[i]-x[i-1]+mj[i-1];
			mj[1]=0;
		}
		if(mj[n]/d==mj[n]/(d-1)-d){
			cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
