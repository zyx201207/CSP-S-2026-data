#include<bits/stdc++.h>
using namespace std;
long long val[1000006],pre[1000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	long long ca;
	cin>>n>>ca;
	for(int i=1;i<=n;i++)cin>>val[i];
	sort(val+1,val+n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+val[i];
	int out=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,mid,ans=r;
		while(l<=r){
			mid=l+r>>1;
			if((i-mid)*val[i]-(pre[i-1]-pre[mid-1])<=ca)r=mid-1,ans=mid;
			else l=mid+1; 
		}
		out=max(out,i-ans+1);
	}
	cout<<out;
	return 0;
}
//I AK IOI
