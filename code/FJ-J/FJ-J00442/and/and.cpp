#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
long long a[N],maxx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i]==a[j]){
					continue;
				}
				int t=(a[i] & a[j]);
				if(t>maxx){
					maxx=t;
				}
			}
		}
	}else if(m==3){
		int k=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(a[i]==a[j] || a[i]==a[k] || a[j]==a[k]){
						continue;
					}
					int t=(a[i] & a[j] & a[k]);
					if(t>maxx){
						maxx=t;
					}
				}
			}
		}
	}else if(m==4){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					for(int l=1;l<=n;l++){
						if(a[i]==a[j] || a[i]==a[k] || a[j]==a[k] || a[i]==a[l] || a[j]==a[l] || a[k]==a[l]){
							continue;
						}
						int t=(a[i] & a[j] & a[k] & a[l]);
						if(t>maxx){
							maxx=t;
						}
					}
				}
			}
		}
	}else if(m==5){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					for(int l=1;l<=n;l++){
						for(int x=1;x<=n;x++){
							if(a[i]==a[j] || a[i]==a[k] || a[j]==a[k] || a[i]==a[l] || a[j]==a[l] || a[k]==a[l] || a[i]==a[x] || a[j]==a[x] || a[k]==a[x] || a[l]==a[x]){
								continue;
							}
							int t=(a[i] & a[j] & a[k] & a[l] & a[x]);
							if(t>maxx){
								maxx=t;
							}
						}
					}
				}
			}
		}
	}
	cout<<maxx;
	return 0;
}
