#include<bits/stdc++.h>
using namespace std;
long long a[200010];
long long n,m,maxn=INT_MIN,s=2e30-1;
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		s&=a[i];
    }
    if(m==1){
		cout<<maxn;
		return 0;
	}
	if(m==n){
		cout<<s;
		return 0;
	}
	if(m==2){
		maxn=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				s&=a[i];
				s&=a[j];
				maxn=max(maxn,s);
				s=2e30-1;
			}
		}
		cout<<maxn;
	}
	if(m==3){
		maxn=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					s&=a[i];
					s&=a[j];
					s&=a[k];
					//cout<<s<<" "<<i<<" "<<j<<" "<<k<<"\n";
					maxn=max(maxn,s);
					s=2e30-1;
				}
			}
		}
		cout<<maxn;
	}
	if(m==4){
		maxn=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int t=k+1;t<=n;t++){
						s&=a[i];
						s&=a[j];
						s&=a[k];
						s&=a[t];
						maxn=max(maxn,s);
						s=2e30-1;
					}
				}
			}
		}
		cout<<maxn;
	}
	return 0;
}
