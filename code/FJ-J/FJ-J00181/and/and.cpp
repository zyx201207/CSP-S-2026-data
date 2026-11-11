#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1); 
	if(m==1){
		cout<<a[n];
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
	}
	if(m==2){
		int maxn=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(((a[i]&a[j])>=maxn)&&(a[i]!=a[j])){
					maxn=(a[i]&a[j]);
				}
			}
		}
		cout<<maxn;
	}
	
	if(m==3){
		int maxn=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(((a[i]&a[j]&a[k])>=maxn)&&(a[i]!=a[j])&&(a[j]!=a[k])&&(a[k]!=a[i])){
						maxn=(a[i]&a[j]&a[k]);
					}
				}
			}
		}
		cout<<maxn;
	}
	return 0;	
}
