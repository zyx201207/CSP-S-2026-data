#include<bits/stdc++.h>
using namespace std;
long long c,t;
long long n,d;
long long x[2000001],mp[2000001];
long long ans[100001];
bool check(long long l,long long r){
	long long cnt1,cnt2=0,num=0;
	if(x[r]-x[l]%d==0)
		cnt1=(x[r]-x[l])/d;
	else
		cnt1=(x[r]-x[l])/d+1;
	for(int i=l;i<r;i++){
		int j;
		for(j=l+1;j<=r;j++)
			for(int k=1;k<=d;k++)
				if(x[i]+k>=x[j])cnt2++;
		if(j==r&&cnt2==cnt1)num++;
	}
	if(num==2)return true;
	else return false;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	memset(ans,0,sizeof(ans));
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[i];
			mp[x[i]]=1;
		}
		for(int p=1;p<n;p++)
			for(int q=p+1;q<=n;q++)
				if(check(p,q))
					ans[i]++;
	}
	for(int i=1;i<=t;i++)cout<<ans[i]<<endl;
	return 0;
}
