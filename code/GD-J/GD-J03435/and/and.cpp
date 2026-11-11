#include<bits/stdc++.h>
using namespace std;
long long n,m;int maxn=-1;
long long a[200003];
bool used[200003]={false};
int solve(int x,int num){
	
	int maxnum=-1,newx;
	for (int i=0;i<n;i++){
		if (used[i]) continue;
		if (num==1) {
			newx=a[i];	
		}
		else newx=newx&a[i];
		maxnum=max(newx,maxnum);
		used[i]=true;
	}
	if (num==m) {
		return x;
	}
	return solve(maxnum,num+1);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>a[i];
		if (a[i]>=maxn) maxn=a[i];
	}
	if (m==1) cout<<maxn;
	solve(1,1);
} 
