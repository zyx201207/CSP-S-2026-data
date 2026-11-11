#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	
	long long abc;
	
	if(m==1){
		abc=-1;
		for(int i=1;i<=n;++i){
			if(a[i]>abc) abc=a[i];
		}
		cout<<abc;
	}
	else if(m==2){
		long long bcd=-1;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				//cout<<i<<' '<<j<<' '<<(i&j)<<'\n';
				if((a[i]&a[j])>bcd) bcd=(a[i]&a[j]);
			}
		}
		cout<<bcd;
	}
	else if(m==n){
		long long cnt=a[1];
		for(int i=1;i<n;++i){
			cnt=(cnt&a[i+1]);
		}
		cout<<cnt;
	}
	else if(m==n-1){
		int c=1,cde=-1;
		for(int i=1;i<=n;++i){
			long long cnt=a[1];
			for(int j=1;j<=n;++j){
				if(c==j) continue;
				else cnt=(cnt&a[i+1]);
			}
			if(cnt>cde) cde=cnt;
			c++;
		}
		cout<<cde;
	}
	else cout<<abc;
	//cout<<(3&15);
	return 0;
}
