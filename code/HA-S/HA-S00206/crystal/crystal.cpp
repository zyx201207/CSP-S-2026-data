#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long ans,n,m=0;
	long long a[10000]=0;
	long long u=0;
	long long s[10000]=0;
	long long cnt=0;
	cin>>n,m>>endl;
	for(int i=0;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i = 0;i <= n;i++){
		if(a[i]==a[i+1]){
			cout<<n;
			return 0;
		}else if(a[i+1]-a[i]=a[i+2]-a[i+1]){
			long long ans=0;
			long long may+=a[i+1]-a[i];
		    m-=may;
		    ans=m;
		    cout<<n-ans;
		    return 0;
		}
		
	}
	s[0]=a[0]
	for(int j=0;j<=n;j++){
		s[j]=a[i+1]-a[i];	
	}
	sort(s,s+n);
	for(int c=0;c<=n;c++){
		cnt+=s[c]+cnt;
		u++;
		if(cnt>m){
			break;
		}
	}
	cout<<u+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
