#include<bits/stdc++.h>
using namespace std;

long long a[500010];
int n;
long long m;

int jisuan(long long zhi,int mid){
	int ans=1,op=m;
	for(int i=mid-1;i>=1;i--){
		int cost=zhi-a[i];
		if(op>=cost){
			op=op-cost;
			ans++;	
		}else if(op<cost){
			break;
		}
	}
	return ans;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int sum=0;
	for(int i=2;i<=n;i++){
		int q=jisuan(a[i],i);
		sum=max(sum,q);
		
	}	
	cout<<sum;
	return 0;
}

