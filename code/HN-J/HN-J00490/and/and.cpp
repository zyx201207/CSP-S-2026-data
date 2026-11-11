#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	if(m==1){
		int maxw=a[1];
		for(int i=2;i<=n;i++){
    	    maxw=max(maxw,a[i]);
	    }
	    cout<<maxw;
	}else if(m==2){
		int maxw=(a[1]&a[2]);
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxw=max(maxw,(a[i]&a[j]));
			}
		}
		cout<<maxw;
	}
	return 0;
}
