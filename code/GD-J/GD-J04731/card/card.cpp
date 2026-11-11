#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const int N=5e5+10;
ll n,m,a[N],w[N],ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	if(m==2&&n>=500){
		for(int i=n;i>=1;i--){
			ans[a[n]]++;
			if(a[i]!=a[n])
			    ans[a[i]]++;
		}
		cout<<ans[1]<<" "<<ans[2];
		return 0;
	} 
	if(n>=5000&&m>=3000)
		for(int i=n;i>=1;i--)
			if(a[i]!=a[i+1]){
				ans[a[i]]+=i;
		for(int i=1;i<=m;i++)
		    cout<<ans[i]<<" ";
		return 0;
	}
	for(int k=1;k<=n;k++){
		memset(w,0,sizeof(w));
		for(int i=k;i<=n;i++){
	    	if(w[a[i]]){
	    		for(int j=w[a[i]]+1;j<i;j++)
	    		    w[a[j]]=0;
			}
			w[a[i]]=i;
		}
		for(int i=1;i<=m;i++)
			if(w[i]) ans[i]++;
	}
	for(int i=1;i<=m;i++)
	    cout<<ans[i]<<" ";
	return 0;
} 
