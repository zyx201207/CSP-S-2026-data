#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
queue<long long> q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long cnt=0,maxx=0;
	long long ans=0;
	for(int i=1;i<=n;i++){
		long long siz=0;
		if(!q.empty()){
			siz=q.size();
			ans=max(ans,siz);
		}
		if(q.empty()){
			q.push(a[i]);
			maxx=a[i];
		}
		else{
			while(!q.empty()&&cnt+((a[i]-maxx)*q.size())>m){
				cnt-=(maxx-q.front());
				q.pop();
			}
			cnt+=(a[i]-maxx)*q.size();
			maxx=a[i];
			q.push(a[i]);
		}
		if(!q.empty()){
			siz=q.size();
		}
		ans=max(ans,siz);
	}
	cout<<ans;
	return 0;
}
