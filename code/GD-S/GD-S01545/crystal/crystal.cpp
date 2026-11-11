#include<bits/stdc++.h>
using namespace std;
long long n,m,e[50005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>e[i];
	}
	sort(e+1,e+n+1);
  
	long long mt=m;
	long long maxn=0;
	for(int i=2;i<=n;i++){
		mt=m;
		ans=0;
		for(int j=i-1;j>=1;j--){
			if(mt-(e[i]-e[j])<0) {
				break;
			}
			mt-=(e[i]-e[j]);
			ans++;
			if(maxn<=ans){
				maxn=ans;
			}
		}
		
	}
	maxn++;
	cout<<maxn;
}
