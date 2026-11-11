#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
int n;
int a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	
	int lb=1,rb=n,l=1,r=a[n];
	int ans=0;
	while(lb<rb){
		int dl=a[lb]-l+1;
		int dr=r;
		if(c[lb]!=c[rb])ans+=min(dl,dr);
		if(dl<dr){
			r-=dl;
			lb++,l=1;
		}
		else{
			l+=dr;
			rb--,r=a[rb];
		}
	}
	
	cout<<ans<<'\n';
	
	return 0;
}
