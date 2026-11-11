#include<bits/stdc++.h>
using namespace std;
long long a[1000010],s[1000010],n,m,ans;
bool check(int x){
	long long minn=LONG_LONG_MAX;//,tmp=0,tmp2=0,tmp3=0;
	for(int i=1;i<=n-x+1;i++)
	{
		//tmp=0;tmp2=0;tmp3=0;
		//for(int j=i;j<=i+x-1;j++)tmp+=a[i+x-1]-a[j],tmp2+=a[j],tmp3+=a[i+x-1];
		minn=min(minn,a[i+x-1]*x-(s[i+x-1]-s[i-1]));
		//cout<<i<<" "<<i+x-1<<" "<<" "<<x<<" "<<a[i+x-1]*x-(s[i+x-1]-s[i-1])<<" "<<tmp<<" "<<tmp2<<" "<<tmp3<<" "<<tmp3-tmp2<<" "<<a[i+x-1]*x<<" "<<s[i+x-1]-s[i-1]<<endl;
	}
	if(minn<=m)return true;else return false;
}
int main(){
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	cin>>n>>m;for(int i=1;i<=n;i++){cin>>a[i];}
	sort(a+1,a+n+1);for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int l=1,r=n;
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid)){ans=max(ans,mid);l=mid+1;}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
//six seven six seven six seven six seven
//zhezhongti wo juran yaoxie 1h...gaile 30min faxian qianzhuihe xiezai paixu qianmianle
//laodingzuishuai
