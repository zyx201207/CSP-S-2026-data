#include<bits/stdc++.h>
using namespace std;
long long a[200005],maxx=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(long long i=1;i<=n;i++){
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	if(m==2){
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				maxx=max(maxx,(a[i]&a[j]));
			}
		}
		cout<<maxx;
	}
	return 0;
}
