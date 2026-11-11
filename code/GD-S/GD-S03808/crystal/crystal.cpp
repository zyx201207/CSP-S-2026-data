#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500001],b[500001],maxn=-1,num,pre[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=1;i<=n;i++){
		b[i]=(i-1)*(a[i]-a[i-1])/*+b[i-1]*/;
		pre[i]=b[i]+pre[i-1];
	}
	for(int i=1;i<=n;i++){
		num=0;
		if(i==1){
			maxn=1;
			for(int j=1;j<=n;j++){
				if(pre[j]<=m)num++;
				else break;
			}
			if(num==n){
				cout<<num;
				return 0;
			}
			maxn=max(maxn,num);
			continue;
		}
		for(int j=i-1;j<=n;j++){
			if(pre[j]-pre[i-1]<=m)num++;
			else break;
		}
		if(num==n-i+1){
			cout<<num;
			return 0;
		}
		maxn=max(maxn,num);
	}
	cout<<maxn;
	return 0;
}//天灵灵，地灵灵，给个一等行不行！ 
