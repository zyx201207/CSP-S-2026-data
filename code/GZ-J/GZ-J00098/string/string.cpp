//毕节七星关东辰实验学校 刘杰 GZ-J00098
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MX=2e5+10;
int a[MX];char b[MX];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		sum+=a[i];
	}
	int l=0,r=0;
	int ln=1,rn=n;
	int ans=0;
	while(l+r<sum){
		if(a[ln]<a[rn]){
			l+=a[ln];
			r+=a[ln];
			a[rn]-=a[ln];
			if(b[ln]!=b[rn]){
				ans+=a[ln];
			}
			ln++;
		}
		else{
			l+=a[rn];
			r+=a[rn];
			a[ln]-=a[rn];
			if(b[ln]!=b[rn]){
				ans+=a[rn];
			}
			rn--;
		}
	}
	cout<<ans<<endl;
} 
