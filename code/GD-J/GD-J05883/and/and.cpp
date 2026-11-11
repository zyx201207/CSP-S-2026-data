#include <bits/stdc++.h>
using namespace std;
long long n=0,m=0,qq_max=LLONG_MIN;
long long a[100050];
long long k[100050];
bool kk[100050];
void tfs(long long v){
	
	if(v==m) {
		long long cut=k[0];
		for(long long i=0;i<m;i++){
			cut=cut&k[i];
		}
		qq_max=max(qq_max,cut);
		return;
	}
	for(long long i=v;i<n;i++){
		if(kk[i]==0){
			k[v]=a[i];
			kk[i]=1;
			tfs(v+1);
			kk[i]=0;
		}
		
		
	}
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++) {
		cin>>a[i];
	}
	tfs(0);
	cout<<qq_max;
	return 0;
}


