#include <bits/stdc++.h>

using namespace std;

const int N=2e5+10;
long long n,m,ans,maxx,q,l,p;
long long a[N];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	q=n;p=m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		for(long long i=1;i<=n;i++){
	    	maxx=max(a[i],maxx);
     	}
		cout<<maxx;
		return 0;
	}
	else if(m==n){
		ans=a[1];
		for(long long i=1;i<n;i++){
	    	ans=(ans&a[i+1]);
     	}
	}
	else if(m==2){
		for(long long i=1;i<=n;i++){
			for(long long j=q;j>=i;j--){
				if(i!=j) maxx=max(maxx,(a[i]&a[j]));
			}
			ans=max(ans,maxx);
		}
	}
	else{
		ans=0;
		for(long long i=1;i<=n;i++){
		    l=a[i];
			for(long long j=q;j>i;j--){
				long long t=j;
				while(1){
					l=(l&a[t]);
					t--;p++;
					if(p==(m-1)) break;
				}
				maxx=max(maxx,l);
			}
			p=0;
			ans=max(ans,maxx);
		}
	}
	cout<<ans;
	return 0;
}
