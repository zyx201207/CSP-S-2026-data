#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;

long long a[N];

int main(){
	
	freopen("and.in","w",stdin);
	freopen("and.out","r",stdout);
	
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
		
	if(m==1){
		long long maxn=-1;
		for(int i=1;i<=n;i++)
		    if(a[i]>maxn)
		        maxn=a[i];
		cout<<maxn<<endl;
		return 0;
	}
	else if(m==2){
		long long a1,a2;
		long long maxn=-1;
		for(int i=1;i<=n;i++)
		    for(int j=1;j<=n;j++)
		    	if(a[i]==a[j] && a[i]>maxn)
		    	    maxn=a[i];
		cout<<maxn<<endl;
		return 0;
	}
	
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=n-1;i>=1;i--){
		if(m==0) break;
		ans=a[i+1]&a[i];
		a[i]=ans;
	}
	cout<<ans<<endl;
	
	return 0;
}





