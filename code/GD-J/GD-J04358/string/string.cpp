#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N=2e5+5;
int n,a[N],cnt,sum;
char c[N];
string s;
bool f=1;
signed main(){
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=n*a[i];
		if(sum>1000000000) f=0;
	}
	if(f==0){
		int l=1,r=n;
		while(l<=r){
			int mn=min(a[l],a[r]);
			a[l]-=mn;
			a[r]-=mn;
			if(a[l]==0) l++;
			if(a[r]==0) r--;
			if(c[l]!=c[r]){
				cnt+=mn;
			}
		}
		cout<<cnt;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s=s+c[i];
		}
	}
	int m=s.size();
	for(int i=0;i<m/2+1;i++){
		if(s[i]!=s[m-i-1]) cnt++;
	}	
	cout<<cnt;
	return 0;
}
