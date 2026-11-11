#include<bits/stdc++.h>
using namespace std;

int n,ans=INT_MIN;
long long m,a[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	
	for(int i=1;i<=n;i++){
		int q=m,cnt=1;	
		for(int l=1;l<i;l++){
			int s=a[i]-a[l];
			if(s<=q){
				q-=s;
				cnt++;
			}else{
				break;
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
} 
