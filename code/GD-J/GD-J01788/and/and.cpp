#include<bits/stdc++.h>
using namespace std;
long long n,m,z=0;
long long ql[1000001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>ql[i];
	}
	if(n==m){
		int x=ql[1];
		for(long long i=2;i<=n;i++){
			x=x&ql[i];
	    }
	    cout<<x;
	    return 0;
	}
	if(m==1){
		sort(ql+1,ql+n+1);
		cout<<ql[n];
		return 0;
	}
	if(m==2){
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				long long y=ql[i]&ql[j];
				z=max(y,z);
			}
		}
		cout<<z;
	}
	if(m==3){
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				for(long long k=j+1;k<=n;k++){
					long long y=ql[i]&ql[j]&ql[k];
					z=max(y,z);
				}
			}
		}
		cout<<z;
	}
	return 0;
}
