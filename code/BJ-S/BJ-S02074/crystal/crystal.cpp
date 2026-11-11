#include<bits/stdc++.h>
using namespace std;
int n,j=0,k=0;
long long m,ans=0,sum=0,su=0,ans1=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int a[500010];
    for(int i = 0;i < n;i++){
	    cin>>a[i];
	    ans+=a[i];
	}
	for(int i = 0;i < n;i++){
	    if(sum/n==a[i]){
	        k++;
	    }
	}
	if(k == n){
	     cout<<n;
	     return 0;
	}
    int all;
    all=ans+m;
	for(int i = 0;i < n;i++){
	    for(int jie = 0;jie < 100000;jie++){
		     if(a[i] < all/jie && all/jie - a[i] >= m){
				m=all/jie-a[i];
				j++;
			}else if(a[i] == all/jie){
				j++;
			}

			if(j >= su){
			    ans1=j;
			}
		}
	}
	cout<<ans1;
    return 0;
}
