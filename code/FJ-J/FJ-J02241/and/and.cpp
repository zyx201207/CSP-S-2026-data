#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],ans;
inline void dfs(int x,int step,int sum){
//	cout<<sum<<endl;
	if(step==m){
		ans=max(ans,sum);
		return;
	}
	for(int i=x+1;i<=n-(m-step)+1;i++){
		dfs(i,step+1,(sum&a[i]));
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(0,0,INT_MAX);
		cout<<ans<<endl;
	}else if(m==1){
		int ma=0;
		for(int i=1;i<=n;i++){
			ma=max(a[i],ma);
		}
		cout<<ma<<endl;
	}else if(m==n){
		ans=INT_MAX;
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans<<endl;
	}else if(m==2){
		int ma=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ma=max(ma,a[i]&a[j]);
			}
		}
		cout<<ma<<endl;
	}else{
		sort(a+1,a+1+n);
		cout<<a[m];
	}
	return 0;
}