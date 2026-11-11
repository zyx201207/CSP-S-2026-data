#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F(i,a,b) for(int i=(a);i<=(b);i++)
#define DF(i,a,b) for(int i=(a);i>=(b);i--)
const int N=5e5+10;
int n,m,a[N],s[N],ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	F(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	F(i,1,n)s[i]=s[i-1]+a[i];
//	F(i,1,n)cout<<a[i]<<" ";
	F(i,1,n){
		int L=1,R=i,j=R;
		while(L<=R){
			int mid=(L+R)>>1;
			if(a[i]*(i-mid+1)<=m+(s[i]-s[mid-1]))j=mid,R=mid-1;
			else L=mid+1;
		}
//		cout<<(i-j+1)<<"\n";
//		if((i-j+1)==6){
//			cout<<a[i]*(i-j+1)<<" "<<(m+(s[i]-s[j-1]))<<"\n";
//			cout<<a[i]<<" "<<s[i]<<" "<<s[j-1]<<'\n';
//		}
		ans=max(ans,i-j+1);
	}
	cout<<ans<<"\n";
	return 0;
}
/*
5 5
1 2 4 8 9

3 3
-4 -3 -1

4 58
45 6 -42 37

9 80
-14 42 12 -24 9 -15 -28 -28 22
*/
