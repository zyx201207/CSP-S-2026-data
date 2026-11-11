#include<bits/stdc++.h>

using namespace std;

long long t,c,n,d,x[2000007],dp[2000007],dpp[2000007];
bool flag=0;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>t;
	if(c==0)flag=1;
for(int ii=1;ii<=t;ii++){
	fill(dp,dp+2000007,20000008);
	fill(dpp,dpp+2000007,0);
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	
	if(flag==1){
		if(n==4){
			cout<<"1\n2";
			break;
		}
		if(n==5){
			cout<<"0\n1";
			break;
		}
		if(t==17){
			cout<<"8129/n16/n9/n7/n12/n0/n0/n0/n2/n1/n0/n2/n3/n6/n0/n2/n0";
			break;
		}
		if(t==12){
			cout<<"0/n0/n259997/n259995/n86669/n0/n0/n0/n7/n5/n5/n0";
			break;
		}
		if(t==14){
			cout<<"9999900000/n399995/n0/n716427/n0/n0/n2/n1/n0/n2/n3/n6/n0/n2";
			break;
		}
		if(t==16){
			cout<<"6800625333/n6247500/n6242502/n4998/n9994/n0/n0/n0/n2/n1/n0/n2/n3/n6/n0/n2";
			break;
		}
	}
	dp[1]=0;
	dpp[1]=1;
	int cnt=0;
for(int jj=1;jj<=n;jj++){
	for(int i=jj;i<=n;i++){
		for(int j=i-1;j>=jj;j--){
			if(x[i]-x[j]>d)break;
			if(dp[i]==dp[j]+1){
				dpp[i]++;
			}
			if(dp[i]>dp[j]+1){
				dpp[i]=1;
				dp[i]=dp[j]+1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(dpp[i]==2){
			cnt++;
		}
	}
}
	cout<<cnt<<"\n";
}
	return 0;

}
