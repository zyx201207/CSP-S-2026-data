#include<bits/stdc++.h>
using namespace std;
const int mxn=5*10000+5;
long long n,m,sum=0,ans=-1;
long long a[mxn];
long long cnt[mxn];
int main()
{
	ios::syn_with_stdic(false);
	int tie(0);
	//freopen("crystal.in","r","stdin")
	//freopen("crystal.out","w","stdout")
	cin>>n>>m;
	for(int i;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	if(n<=5000&&m<=1000000000){
		for(long long i;i<n;i++){
			for(long long j=i-1;j>=0;j--){
				sum+=a[i]-a[j];
				if(sum<n){
					ans=
				}
			}
		}
	}
	
	cout<<m;
	
	return 0;
	
	
}

