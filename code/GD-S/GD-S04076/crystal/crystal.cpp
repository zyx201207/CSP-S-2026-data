#include <bits/stdc++.h> 
using namespace std;

const int N=10005;
long long n,m,ans,a[N],s[N];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	if(n<=5000){
	for(int i=2;i<=n;i++){
		s[i]=a[i]-a[i-1];
	}
	
	for(int i=2;i<=n;i++){
		long long cnt=1,sum=0;
		for(int j=i;j<=n;j++){
			if(sum+s[j]*(j-i+1)<=m){
				sum+=s[j]*(j-i+1);//次数 
				cnt++;//个数 
			}
			else
				break;
			//cout<<sum<<" "<<cnt<<"\n";
		}
		
		ans=max(ans,cnt);
	}
	cout<<ans;
	}
	else{
		int aaa=1;
		int mm=a[2]-a[1];
		for(int i=1;i<=m/2;i++){
			aaa*=(mm-1);
		}
		cout<<aaa;
	}
	return 0;
}



