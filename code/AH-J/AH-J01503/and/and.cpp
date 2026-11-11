#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200050],num,ma=0,t1,t2,b[200050],ans=0;
void dfs(int i,int t){
	if(t==m){
		int cnt=b[1]&b[2];
		for(int i=3;i<=n;i++){
			cnt=cnt&b[i];
		}
		if(cnt>ans) ans=cnt;
	}
	t++;
	for(int j=i+1;j<=n;j++){
		b[t]=a[j];
		dfs(j,t);
	}
	t--;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1) t1=0;
		num=a[i]&num;
		ma=max(ma,a[i]);
	}
	if(n<=20){
		dfs(0,0);
		cout<<ans;
	}else if(m==n) cout<<num;
	else if(m==1) cout<<ma;
	else if(m==2){
		int s=0;
		for(int i=1;i<=n;i++){
			int c;
			for(int j=i+1;j<=n;j++){
				c=a[i]&a[j];
				s=max(s,c);
			}
		}
		cout<<s;
	}else{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
	}
	return 0;
}
