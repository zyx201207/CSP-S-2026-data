#include<bits\stdc++.h>
using namespace std;
long long n,m;
long long ans;
long long a[200010];
long long d[200010];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		ans=a[1];
		for(int i=2;i<=n;i){
		    ans=ans&a[i];
	    }
		cout<<ans;
	}else if(m==2){
		ans=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
			    ans=max(ans,a[i]&a[j]);
		   }
		}
		cout<<ans;
	}else if(m==1){
		ans=INT_MIN;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}else{
		sort(a+1,a+n+1,cmp);
		ans=a[1];
		for(int i=2;i<=m;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}
	return 0;
} 
