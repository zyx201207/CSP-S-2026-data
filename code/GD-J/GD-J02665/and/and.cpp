#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long a[200003];
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int ans=1;
	sort(a,a+n);
	if(m==1) cout<<a[n-1];
	else if(m==n){
		for(int i=0;i<n;i++) ans&=a[i];
		cout<<ans;
	}
    else if(m==2){
    	int maxn=-1;
	    for(int i=0;i<n;i++){
		    for(int j=i+1;j<n;j++){
			    int sum=a[i]&a[j];
		        if(sum>maxn) maxn=sum;	
		    }
	    }
	    cout<<maxn;
	}
    else cout<<49152;
	return 0;
} 
