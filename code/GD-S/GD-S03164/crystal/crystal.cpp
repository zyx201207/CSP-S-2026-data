#include<bits/stdc++.h> 
using namespace std;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;long long m;cin>>n>>m; 
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	int j=0;
	int ans=1;
	long long maxn=0;
	for(int i=1;i<n;i++){
		if(a[i]-a[i-1]+maxn<=m){
		maxn+=(i-j)*(a[i]-a[i-1]);
		}
		else{ans=max(ans,i-j);maxn-=(a[i]-a[j]);j++;
		}
	
	}
		cout<<ans<<endl;
	return 0;
}
