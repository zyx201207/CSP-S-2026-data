#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200005];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxn=0;
	if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(a[i],maxn);
		}
		cout<<maxn;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max((a[i]&a[j]),maxn);
			}
		}
		cout<<maxn;
		return 0;
	}
	if(m==3){
		for(int w=1;w<=n;w++){
		    for(int i=w+1;i<=n;i++){
			    for(int j=i+1;j<=n;j++){
				    maxn=max((a[w]&a[i]&a[j]),maxn);
			    }
		    }
        }
		cout<<maxn;
		return 0;
	}
	if(m==4){
		for(int e=1;e<=n;e++){
		    for(int w=e+1;w<=n;w++){
		        for(int i=w+1;i<=n;i++){
			        for(int j=i+1;j<=n;j++){
				        maxn=max((a[w]&a[i]&a[j]),maxn);
			        }
		        }
            }
        }
		cout<<maxn;
		return 0;
	}
	if(m==5){
		for(int r=1;r<=n;r++){
		    for(int e=r+1;e<=n;e++){
		        for(int w=e+1;w<=n;w++){
		            for(int i=w+1;i<=n;i++){
			            for(int j=i+1;j<=n;j++){
				            maxn=max((a[w]&a[i]&a[j]),maxn);
			            }
		            }
                }
            }
        }
		cout<<maxn;
		return 0;
	}
} 
