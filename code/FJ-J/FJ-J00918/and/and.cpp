#include<bits/stdc++.h>
using namespace std;
                                               
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int a[n+5];
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<0;
		return 0;
	} 
	if (m==n){
		long long ans=a[1];
		for (int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans<<"\n";
		return 0;
	}
	if (m==2){
		long long maxn=-1e9;
		for(int i=1;i<=n;i++){
			for (int j=i+1;j<=n;j++){
				long long cc=a[i]&a[j];
				maxn=max(maxn,cc);
			}
		}
		cout<<maxn<<"\n";
	}
	if (m==n-1){
		long long maxn=-1e9;
		for (int i=1;i<=n;i++){
			long long cc=2251799813685247;
			for (int j=1;j<=n;j++){
				if (j==i) continue;
				cc=cc&a[j];
			}
			maxn=max(maxn,cc);
		}
		cout<<maxn<<"\n";
	}
	return 0;                                         
} 
                                                    
                                                 
