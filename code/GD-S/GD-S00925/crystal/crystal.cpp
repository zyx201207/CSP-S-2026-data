#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ans=0;
	long long l=1,sum=0,num=1;
	a[0]=0;
	for(int i=2;i<=n;i++){//以I为基准
		while(true){
			if(sum+1LL*num*(a[i]-a[i-1])<=m){
				sum+=1LL*num*(a[i]-a[i-1]);
				num++;
				break;
			}
			if(l==i)  break;
			sum-=(a[i-1]-a[l]);
			num--;l++;
		}
		ans=max(ans,num);
	}
	cout<<ans;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
