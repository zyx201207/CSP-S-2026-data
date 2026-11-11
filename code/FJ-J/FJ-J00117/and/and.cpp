#include<bits/stdc++.h>
using namespace std;
int a[200005],maxn=1,cnt=1; 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	cnt=max(cnt,a[i]);
	}
	if(m==n){
		for(int i=1;i<=n;i++){
			maxn=maxn&a[i];
		}
		cout<<maxn;
		return 0;
	}
	if(m==n-1){
		int w=0,x=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j!=i){
					x=x&a[j];
				}
				w=max(w,x);
			}
		}
		cout<<w;
		return 0;
	}
	if(m==1){
		cout<<cnt;
		return 0;
	}
	if(m==2){
		int w=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j!=i){
					int x=a[i]&a[j];
					w=max(w,x);
				}
			}
		}
		cout<<w;
		return 0;
	}
	
	return 0;
}