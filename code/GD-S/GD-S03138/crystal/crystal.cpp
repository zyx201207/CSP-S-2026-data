#include<bits/stdc++.h> 
#define int long long 
using namespace std;
const int N=5e5+5;
int a[N],s[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;cin>>n>>m;
	int cnt=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=2;i<=n;i++){
		for(int j=0;j<i;j++){
			if(i-j<cnt) break;
			else{
				if((s[i]-s[j]+m)<a[i]*(i-j)) continue;
				else {
					cnt=max(cnt,i-j);
					break;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
