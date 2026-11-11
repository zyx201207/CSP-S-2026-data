#include<bits/stdc++.h>
using namespace std;
long long a[200005],n,m,ans;
bool cmp(long long a,long long b){
	return a>b;
}
void solve(int t){
	for(int i=t;i<=t+m-1;i++){
		if(a[i]!=0){
			ans=ans&a[i];
		}else{
			int j=i;
			while(a[j]==0){
				j++;
			}ans=a[j];
			solve(j);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	solve(1);
	cout<<ans;
	return 0;
} 
