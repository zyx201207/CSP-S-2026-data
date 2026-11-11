#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,n,d,a[2000005],ans,sum,an;
void dfs(int point,int end,ll num){
	if(point==end){
		if(num<ans){
			sum=1;
			ans=num;
		}else if(num==ans){
			sum++;
		}
	}
	for(int i=point+1;i<=end;i++){
		if(a[i]-a[point]>d) break;
		dfs(i,end,num+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		an=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n-3;i++){
			for(int j=i+3;j<=n;j++){
				if(a[j]-a[i]<=d) continue;
				ans=INT_MAX,sum=0;
				dfs(i,j,0);
				if(sum==2) an++;
			}
		}
		cout<<an;
	}
	return 0;
}
