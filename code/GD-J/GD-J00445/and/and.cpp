#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll N[200010],M[200010];
ll ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>N[i];
	}
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				ans=max(ans,N[i]&N[j]);
			}
		}
	}
	else if(m==1){
		for(int i=0;i<n;i++){
			ans=max(ans,N[i]);
		}
	}
	else if(m==n){
		for(int i=0;i<n;i++){
			ans&=N[i];
		}
	}
	cout<<ans;
	return 0;
} 
