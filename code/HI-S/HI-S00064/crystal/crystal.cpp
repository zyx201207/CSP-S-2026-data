#include<bits/stdc++.h>
using namespace std;
long long a[100005],b[100005];
long long n,m,ans=0;
bool cmp(int x,int y)
{
	return x<y;
}
long long sep()
{
	long long x=a[2]-a[1],cnt=0;
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=x)
			return 0;
	}
	if(a[1]>a[n]){
		for(int i=1;i<=n;i++)
		{
			cnt+=a[1]-a[i];
			if(cnt>m) return i-1;
		}
	}
	else{
		for(int i=n-1;i>=1;i--)
		{
			cnt+=a[n]-a[i];
			if(cnt>m) return n-i;
		}
	}
	return n;
}
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin>>n>>m; 
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]++;
	}
	if(sep()){
		cout<<sep();
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=n;i>=1;i--)
	{
		int k=m,j=i;
		long long sum=0;
		while(--j)
		{
			if(k-(a[i]-a[j])>=0){
				k-=a[i]-a[j],sum++;
			}
			else break;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}

