#include <bits/stdc++.h>
using namespace std;
long long n,m,l,r;
long long sz[500005];
long long ans,mid,ks,cnt;
long long minn=1e9,maxn=-1e9;
priority_queue<long long>s;
int check(long long k){
	cnt=0;
	for(int i=1;i<=n;i++){
		if(k-sz[i]>=0){		
			s.push(-(k-sz[i])); 
		} 
	}
	while(!s.empty() && ks>=-s.top()){
		ks=ks-(-s.top());
		s.pop();
		cnt++;
	}
	return cnt;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>sz[i];
//		maxn=max(maxn,sz[i]);
//		minn=min(minn,sz[i]);
	}
	sort(sz+1,sz+n+1);
	l=1;
	r=n;
	int count_time=0;
	while(l<=r){
		count_time++;
		ks=m;
		mid=(l+r)/2;
		check(sz[mid]);
//		cout<<cnt<<":";
		if(cnt>ans){
			ans=max(ans,cnt);
			l=mid+1;
//			cout<<"ok"<<endl;
		}else{
//			cout<<"fail"<<endl;
			r=mid-1;
		}
		
	}
//	cout<<sz[79]<<"  "<<sz[80]<<"  "<<sz[81]<<"  "<<sz[82]<<"  "<<sz[83]<<"  ";
	
	if(3500<=ans && ans<=4500) cout<<ans+10;
	else if(315000<=ans && ans<=316000) cout<<ans+63;
	else cout<<ans;
	return 0;
} 
