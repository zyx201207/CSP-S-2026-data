#include<bits/stdc++.h>
using namespace std;

#define int long long
int m,n,a[1000005],s=0,k=0;
signed main(){

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+n,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			a[i]++;
			if(a[i]>=a[i+1]){
			
				if(m-j<(a[i+2]-a[i])*(i+1)){
					s=i;
				}
				else{
					s=i+1;
					continue;
				}
					

			}

			if(k<s){
				k=s;
			}
		}
    }
    cout<<k;
    

	return 0;
}
