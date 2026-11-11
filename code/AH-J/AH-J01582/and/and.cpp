#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxn=-1,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		ans+=a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<maxn;
	}
	else if(m==n){
		cout<<ans;
	}
	else if(m==2){
		maxn=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}	
		}
		cout<<maxn;
	}
	else{
		int cnt=a[n-m+1];
		for(int i=n-m+1;i<=n;i++){
			cnt&=a[i]; 
		}
		cout<<cnt;
	}
	return 0;
}

