#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
ll len[N];
char a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(ll i=1,t;i<=n;i++){
		cin>>t>>a[i];
		len[i]=len[i-1]+t;
	}
	len[n+1]=LLONG_MAX;
	ll mid=len[n]/2,ans=mid;
	int mi=upper_bound(len+1,len+1+n,mid+1)-len;
	ll ml=len[mi-1]+1,mr=len[mi];
	ll rdc=min(mid-ml+2,mr-mid);
//	cerr<<rdc<<"\n";
	ans-=rdc;
	for(int i=1;len[i]<=mid;i++){//
		ll l=len[i-1]+1,r=len[i];
		ll rl=len[n]+1-r,rr=len[n]+1-l;
//		cerr<<"rl:"<<rl<<endl;
		int j=upper_bound(len+1,len+1+n,rl)-len;
		while(rr>=rl){//
//			cerr<<"rl"<<rl<<",rr:"<<rr<<"\n";
			if(a[j]==a[i]){
				if(len[j]<=rr)
					ans-=len[j]-rl+1;
//					cerr<<len[j]-rl+1<<endl;
				else
					ans-=rr-rl+1;
//					cerr<<rr-rl+1<<endl;
			}
			rl=len[j]+1;
			j++;
		}
	}
	cout<<ans;
	return 0;
}
/*
7
10 a
10 a
10 a
9 b
5 a
10 a
5 b

a a a b b a
1 2 3 4 5 6
*/
