#include<bits/stdc++.h>
using namespace std;
int n,m;
unsigned long long a[200009];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==2){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		cout<<a[n-1];
	}
	if(m==1){
		unsigned long long ans=0;
		for(int i=1;i<=n;i++){
		    cin>>a[i];
		    ans=max(a[i],ans);
	    }
	    cout<<ans;
	}else if(m==n){
		unsigned long long ans=100000000000;
		for(int i=1;i<=n;i++){
		    cin>>a[i];
		    ans=min(a[i],ans);
	    }
	    cout<<ans;
	}else if(m==(n-1)){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		cout<<endl<<a[2];
	}
	
	return 0;
}
