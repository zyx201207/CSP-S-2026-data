#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans;
bool v[200005];
void dfs(long long sum,long long ge,int qi){
	if(ge==m){
		ans=max(ans,sum);
		return;
	}
	for(int i=qi;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			long long huan=sum;
			sum=sum&a[i];
			dfs(sum,ge+1,i);
			v[i]=0;
			sum=huan;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
//	cout<<(12&10);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		for(int i=1;i<=n-m+1;i++){
			dfs(a[i],0,i);
		}
		cout<<ans;
	}else{
		long long ndout=0;
		if(m==1){
			for(int i=1;i<=n;i++){
				ndout=max(ndout,a[i]);
			}
			cout<<ndout;
		}else if(m==2){
//			sort(a+1,a+1+n);
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					ndout=max(ndout,a[i]&a[j]);
				}
			}
			cout<<ndout;
		}else if(m==n){
			ndout=a[1];
			for(int i=2;i<=n;i++){
				ndout=ndout&a[i];
			}
			cout<<ndout;
		}
	}
	return 0;
} 
