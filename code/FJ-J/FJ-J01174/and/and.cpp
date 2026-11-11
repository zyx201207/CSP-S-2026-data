#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],maxx,maxai;
void dfs(int step,int dq,long long dqnum){
	if(step>m){
		maxx=max(maxx,dqnum);
		return;
	}
	if(dq>n)return;
	dfs(step,dq+1,dqnum);
	dfs(step+1,dq+1,dqnum&a[dq]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxai=max(maxai,a[i]);
	}
	if(n<=2000){
		dfs(1,1,pow(2,30)-1);
	} 
	else{
		if(maxai>=4){
			if(m==n-1){
				long long ans1=a[1],ans2=a[2];
				for(int i=1;i<n;i++){
					ans1=ans1&a[i];
					ans2=ans2&a[i+1];
				}
				maxx=max(ans1,ans2);
			}
		}
		else{
			long long j1,j2,j3;
			for(int i=1;i<=n;i++){
				if(a[i]==3) j3++;
				if(a[i]==2) j2++;
				if(a[i]==1) j1++;
			}
			if(j3>=m) maxx=3;
			else if((j2+j3)>=m) maxx=2;
			else if((j1+j3)>=m) maxx=1;
		}
	}
	cout<<maxx;
}
