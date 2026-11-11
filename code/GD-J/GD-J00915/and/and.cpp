#include<bits/stdc++.h>
using namespace std;
long long a[1000100];
long long maxn[1000100];
long long maxi[1000100];
void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int k=0;k<m;k++){
		for(int i=0;i<n;i++){
			if(maxn[k]<a[i]){
				bool f = false;
				for(int j=0;j<k;j++){
					if(i==maxi[j]) f = true;
				}
				if(!f){
					maxn[k]=a[i];
					maxi[k]=i;
				}
			}
		} 
	}
	long long ans = maxn[0];
	for(int i=1;i<m;i++){
		ans &= maxn[i];
	}
	cout<<ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	solve();
	return 0;
}
