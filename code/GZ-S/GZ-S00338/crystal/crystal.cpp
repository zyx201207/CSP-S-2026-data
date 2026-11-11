#include<bits/stdc++.h>//GZ-S00338¶­½úçõ 
using namespace std;
long long n,m,sj[500005],sum[500005]={},ans=1;
bool cmp(int x,int y){
	return x<y;
}
int main()
{
		freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>sj[i];
	}
	if(n<=5000){
	sum[0]=0;sort(sj,sj+n,cmp);
	sj[0]=0;
	for(int i=1;i<n;i++){
		sum[i]=sum[i-1]+sj[i];
	}
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
		long long len=j-i+1;
		if(((sum[j]-sum[i-1]+m)/sj[j])>=len&&(sum[j]-sum[i-1])<=(len*sj[j])){ans=max(ans,len);}
	}
	}
	}
else 
	{
		int a=sj[2]-sj[1];
		for(int i=0;i<500005;i++){
			cout<<a;
			if((a+i*a)*i/2>m){ans=i-1;break;}
		}
	}
	cout<<ans;
	return 0;
}
