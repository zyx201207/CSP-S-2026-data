#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int MAXN = 5e5+5;
ll m,n;
ll a[MAXN],d[MAXN],s[MAXN];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	s[1]=0;
	for(int i=2;i<=n;i++){
		d[i]=a[i]-a[i-1];
		s[i]=s[i-1]+d[i]; 
	}
	int l=1,r=1;
	int ans=1;
	long long v=0;
	while(r!=n){
		r++;
		v+=(r-l)*d[r];
		if(v<=m){
			ans=max(ans,r-l+1);
		}
		else{
			while(v>m&&l<=r){
				v=v-(s[r]-s[l]);
				l++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
} 
