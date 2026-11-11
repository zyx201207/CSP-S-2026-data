#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005],type[200005];
char t;
long long ans;
long long res;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		cin>>t;
		type[i]=t-'a'+1;
		res+=a[i];
	}
	long long mid=res+1>>1;
	//cout<<res<<" "<<mid<<"\n";
	for(long long l=1,r=n,L=0,R=res+1; ; l++)
	{
		if(L+a[l]>mid) break;
		L+=a[l];
		while(R-a[r]>=(res-L+1))
		{
			if(type[r]!=type[l]) ans+=a[r];
			R-=a[r];
			a[r]=0;
			r--;
		}
		if(L>res-R+1)
		{
			if(type[r]!=type[l])
			{
				ans+=L-(res-R+1);
			}
			a[r]-=L-(res-R);
			R=res-L;
		}
		a[l]=0;
	}
	// 最后剩下中间的 
	string last=" ";
	for(int i=1; i<=n; i++)
	{
		while(a[i]--) last+=char(type[i]-1+'a');
	}
	int len=last.size()-1;
	for(int i=1; i<=len/2; i++)
	{
		if(last[i]!=last[len-i+1]) ans++;
	}
	cout<<ans;
	
	return 0;
} 
/* 
构造数据可能会被卡，但是总体最高也就 1e9+ 
*/
