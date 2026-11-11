#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ulp(i,a,b) for(int i=a;i<=b;i++)
#define dlp(i,a,b) for(int i=a;i>=b;i--)
const int N=5e5+5;
int n,m,a[N],last[N],t[N],cnt[N],tt[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	ulp(i,1,n){
		cin>>a[i];
	} 
	dlp(i,n,1){
		if(!last[a[i]]){
			last[a[i]]=i;
		}
		tt[last[a[i]]]++;
	}
	ulp(i,1,n-1){
		if(last[a[i]]!=i)continue;
//		if(last[a[i+1]]!=i+1){
//			tt[last[a[i+1]]]+=tt[i];
//			tt[i]=0;
//		}
		tt[last[a[i+1]]]+=tt[i];
	}
	ulp(i,1,m){
		cout<<tt[last[i]]<<" ";
	}
}
