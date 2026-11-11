#include <bits/stdc++.h>

using namespace std;
long long n,m,a[500010],cnt=0,c,sum=0,t,mx=-1,ans=1,flag=0;
int main()
{   freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	sum+=a[i];
	}
	if(sum==(a[1]+a[n])*n/2){
		if(m%(a[2]-a[1])==0){
			cout<<m/(a[2]-a[1]);
			return 0;
		}
		else{
			cout<<m/(a[2]-a[1])+1;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j==i){
				continue;
			}
			if(j==n){
				flag=0;
				continue;
			}
			if(ans==1 and cnt==0 and j<n and flag==1){
				continue;
			}	
			cnt+=abs(a[j]-a[i]);
			if(cnt>=m){
				mx=max(ans,mx);
				c=max(cnt,c);
				ans=1;
				cnt=0;
				flag=1;
				continue;
			}
			ans++;
					
			
		}
		
		
	
	}
	if(c<=m){
		cout<<n;
		return 0;
	}
	cout<<mx;
    return 0;
}

