#include<bits/stdc++.h>
using namespace std;

const int N=2*1e5;
long long a[N],b[N];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	cout<<m;
	if(m==1){
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			ans=max(a[i],ans);
	    }
		cout<<ans;
		return 0;
	}
	else if(m==2){
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
	    }
	    for(int i=1;i<n;i++){
			for(int j=i;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
	    	}
	    }
	    cout<<ans;
	}
	else if(m==n){
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i==1)ans=a[i];
			else ans=ans&a[i];
	    }
	    cout<<ans;
	    return 0;
	}
	else if(m=n-1){
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
	    }
	    sort(a+1,a+n+1,cmp);
	    for(int i=1;i<=n-1;i++){
			ans=ans&a[i];
	    }
	    cout<<ans;
	    return 0;
	}
	
	return 0;
} 
