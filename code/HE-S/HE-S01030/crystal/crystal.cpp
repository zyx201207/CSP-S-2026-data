#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,s=2e18,e=-2e18,ans;
int ma=-2e18;
int a[500010];
bool A=1,B=1;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s=min(s,a[i]);
		e=max(e,a[i]);
		if(a[i]!=i)A=0;
	}
	int c=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=c)B=0;
	}
	if(A||B){
		sort(a+1,a+n+1,cmp);
		int jz=a[1];
		for(int i=1;i<=n;i++){
			if((m-jz+a[i])>=0){
				m=m-jz+a[i];
				ans++;
			}else{
				cout<<ans;
				return 0; 
			}
		}
	}else{
		sort(a+1,a+n+1);
		priority_queue<int,vector<int>,greater<int> >q;
		for(int i=s;i<=e;i++){
			for(int j=1;j<=n;j++){
				q.push(i-a[j]);
			}
			int sum=0;
			while(q.size()){
				int now=q.top();
				q.pop();
				if(now<0)continue;
				if(sum+now<=m){
					sum=sum+now;
					ans++;
				}else{
					ma=max(ma,ans);
					break;
				}
			}
			ma=max(ma,ans);
			while(q.size()){
				q.pop();
			}
			ans=0;
		}
		cout<<ma;
	}
	return 0;
}
