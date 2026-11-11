#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200010];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxn=-1;
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>maxn){
				maxn=a[i];
			}
		}	
		cout<<maxn;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int t=(a[i]&a[j]);
				if(t>=maxn){
					maxn=t;
				}	
			}
		}
		cout<<maxn;
		return 0;	
	}
	else if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					int t1=(a[i]&a[j]);
					int t2=(t1&a[k]);
					if(t2>=maxn){
						maxn=t2;
					}
				}
			}
		}
		cout<<maxn;
		return 0;		
	}
	return 0;
} 
