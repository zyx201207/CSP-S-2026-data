#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N];
int ans=0,q,ma=-100;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			q=a[i]-a[j];
			if(q>m){
				break;
			} 
			else {
				m-=q;
				ans++;
			}
			
		}
	}
	ma=max(ma,ans);
	cout<<ma-n;
	return 0;
}
