#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+10;
int a[N],ans,s[2008][2008];
int nd(int x,int y){
	int s;
	s=x&y;
	return s;
}
int cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		int sum=a[1];
		for(int i=2;i<=n;i++){
			sum=sum&a[i];
		}
		ans=sum;
	}
	if(m==1){
		sort(a+1,a+n+1,cmp);
		ans=a[1];
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					s[i][j]=0;
				}
				else{
					s[i][j]=a[i]&a[j];
				}
			}
		}
		int maxn=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				maxn=max(s[i][j],maxn);
			}
		}
		ans=maxn;
	}
		if(m!=2&&m!=1&&m!=n){
			sort(a+1,a+n+1,cmp);
			ans=a[1];
			//cout<<ans<<endl;
			for(int i=2;i<=m;i++){
				ans=nd(ans,a[i]);
			}
		}
	cout<<ans<<endl;
	return 0;
}
