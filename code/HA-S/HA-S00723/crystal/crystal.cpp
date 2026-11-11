#include <bits/stdc++.h>
using namespace std;
int a[5000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,maxx=0;
		 cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}		
	for(int i=0;i<n;i++){
		long long ans=1,mm=m;	
		for(int j=i;j<n;j++){	
				mm-=abs(a[j+1]-a[j])*(j-i+1);
				if(mm<0) break;
				ans++;
		}	
		maxx=max(maxx,ans);
	}
	cout<<maxx;
	return 0;
}
