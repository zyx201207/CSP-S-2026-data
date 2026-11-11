#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
#define ll long long
int n,a[N];
int m,s[N],f[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		s[i]=a[i]-a[i-1];
	}
	memset(f,0,sizeof f);
	for(int i=n-1;i>0;i--){
		ll tot=0;
		ll cnt=m; 
		for(int j=i;j>0;j--){
			while(cnt-(tot+s[j])>=0){
				cnt-=tot+s[j];
				tot+=s[j];
				f[i]++;
			}
		}
	}
	int ans=0;
	for(int i=1;i<n;i++){
		ans=max(ans,f[i]);
	}
	cout<<ans+1<<endl;
	return 0;
}
