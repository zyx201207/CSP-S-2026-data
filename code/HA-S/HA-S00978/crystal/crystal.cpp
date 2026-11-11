#include<bits/stdc++.h>
using namespace std;
int n,k,ans,maxx;
long long m,sum;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		sum=m;
		k=i-1;
		ans=1;
		while(k>0){
			if(sum>=a[i]-a[k]){
				sum-=a[i]-a[k];
				k--;
				ans++;	
			}
			else{
				break;
			}
		}
		maxx=max(maxx,ans);
	}
	cout<<maxx;
	return 0;
} 
