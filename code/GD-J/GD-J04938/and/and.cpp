#include<bits/stdc++.h>
using namespace std;
unsigned long long a[200005];
int n,m;
bool cmp(unsigned long long a,unsigned long long b){
	return a<b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	//sort(a+1,a+n+1,cmp);
	unsigned long long maxn=0;
	for(int i=1;i<=n;i++){
		if(m==1){
			maxn=max(maxn,a[i]);
		}
		if(m==2){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		if(m==3){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					maxn=max(maxn,a[i]&a[j]&a[k]);
				}
			}
		}
		if(m==4){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int s=k+1;s<=n;s++){
						maxn=max(maxn,a[i]&a[j]&a[k]&a[s]);
					}
				}
			}
		}
		if(m==5){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int s=k+1;s<=n;s++){
						for(int o=s+1;o<=n;o++){
							maxn=max(maxn,a[i]&a[j]&a[k]&a[s]&a[o]);
						}
					}
				}
			}
		}
	}
	cout<<maxn;
	return 0;
}
