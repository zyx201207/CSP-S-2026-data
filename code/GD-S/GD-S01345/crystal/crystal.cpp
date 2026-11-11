#include<bits/stdc++.h>
using namespace std;

const long long M=5e5+1000;
int n,cnt=1,Max=-1;
long long m,a[M];

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	sort(a+1,a+n+1);
	
	int vis=1;
	long long s=m;
	for(int i=2;i<=n;i++)
	{
		int b=(a[i]-a[i-1])*cnt;
		
		while(s<b&&cnt!=1){
			s=s+(a[i-1]-a[vis]);			
			
			vis++;
			cnt--;
			b=(a[i]-a[i-1])*cnt;
		}
		if(s>=b)
		{	
			s=s-b;
			cnt++;
			Max=max(Max,cnt);
		}		
		
	}

	Max=max(Max,cnt);
	cout<<Max;
	
	return 0;
	
} 
