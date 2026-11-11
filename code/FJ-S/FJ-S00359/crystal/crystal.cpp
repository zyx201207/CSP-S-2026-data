#include<bits/stdc++.h>
using namespace std;
int n,f=1;
long long m,a[500005],t; 
priority_queue<long long>q;
long long sum(int l,int r){
	long long ans=0;
	int k=1;
	for(int i=l+1;i<=r;i++){
		ans=ans+1LL*k*(a[i]-a[i-1]);
		k++;
	}
	return ans;
}
bool check(int x){
	for(int i=x;i<=n;i++){
//		cout<<x<<" "<<sum(i-x+1,i)<<endl;
		if(sum(i-x+1,i)<=m) return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=5000&&m<=1000){
		int ans=0;
		t=m;
		for(int i=1;i<=n;i++){
			m=t;
			while(q.size()) q.pop();
			for(int j=1;j<i;j++){
				q.push(a[j]-a[i]);
			}
			int cnt=0;
			while(q.size()&&m){
				long long c=-q.top();
				q.pop();
				if(c<=m){
					m-=c;
					cnt++;
				}else{
					break;
				}
			}
			ans=max(ans,cnt);
		}
		cout<<ans+1;
	}else if(n<=5000){
		int l=1,r=n;
		while(l<r){
			int mid=(l+r+1)/2;
			if(check(mid)){
				l=mid;
			}else{
				r=mid-1;
			}
		}
		cout<<l<<endl;
	}else{
		long long d=a[2]-a[1];
		int ans=0;
		long long cnt=0,k=1;
		while(1){
			if(cnt+k<=m){
				cnt+=k;
				k+=d;
				ans++;
			}else{
				break;
			}
		}
		cout<<ans+1;
	}
	return 0;
} 
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

4 3
-9 1 2 3

5 6
1 3 5 7 9
*/
