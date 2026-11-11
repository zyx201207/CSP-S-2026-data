#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m;
int ans;
bool flag;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>=3 && (a[i]-a[i-1]) != (a[i-1]-a[i-2])) flag=1;
	}
	if(flag==0){//ÐÔÖÊA 
		int i=n-1;
		while(m>0 && i>=1){
			int t=a[n]-a[i];
			if(m-t<0) break;
			m-=t;
//			cout<<m<<'\n';
			ans++;
			i--;
		}
		cout<<ans+1;
		return 0;
	}
	else{
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			int res=1,p=m;
			int j=i-1;
			while(p>0 && j>=1){
				int t=a[i]-a[j];
				if(p-t<0) break;
				res++;
				p-=t;
				j--;
//				cout<<p<<'\n';
			}
			ans=max(ans,res);
//			cout<<ans<<'\n';
		}
		cout<<ans;
	}
	return 0;
}
/*
7 6
2 4 6 8 10 12 14

5 5
1 2 4 8 9

Oct31==Dec25?
*/
