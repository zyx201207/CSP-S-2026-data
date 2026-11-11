#include<bits/stdc++.h>
using namespace std;

#define int long long
int n;
int a[200005];
char b[200005];
int cnt[200005];
int p=1,q,x,ans;
signed main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		cnt[i]=cnt[i-1]+a[i];
	}
	q=n+1;
	while(cnt[n]-cnt[q-1]<(cnt[n]+1)/2||cnt[p]<(cnt[n]+1)/2){
		if(cnt[p]<cnt[n]-cnt[q-1]){
			p++;
			int xx=x;
			x=min(cnt[p],cnt[n]-cnt[q-1]);
			if(b[p]!=b[q])ans+=(x-xx);
			//cout<<p<<q<<endl;
			//cout<<x<<" "<<xx<<endl; 
		}
		else{
			q--;
			int xx=x;
			x=min(cnt[p],cnt[n]-cnt[q-1]);
			if(b[p]!=b[q])ans+=(x-xx);
			//cout<<p<<q<<endl;
			//cout<<x<<" "<<xx<<endl; 
		}
		
	}
	cout<<ans;
	return 0;
} 
