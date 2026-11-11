#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=5e5+3;

ll n,m;
ll a[N];
ll sum[N];

bool judge(int len){
	if(len>n)return 0;
	ll mi=1e18;
	for(int i=1;i+len-1<=n;i++){
		int l=i,r=i+len-1;
		mi=min(mi,len*a[r]-(sum[r]-sum[l-1]));
	}
	if(mi<=m)return 1;
	return 0;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	int l=1,r=1e9;
	int best=-1;
	while(l<r){
		int mid=ceil((l+r)/2.0);
		if(judge(mid)){
			l=mid;
			best=mid;
		}
		else{
			r=mid-1;
		}
	} 
	
	cout<<best;
	return 0;
} 

