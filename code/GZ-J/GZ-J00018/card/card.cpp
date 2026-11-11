//GZ-J00018 金沙县第三中学  孟彧臣 
#include<bits/stdc++.h>
using namespace std;
#define long long
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m,a[1000000000],b[100000000];
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
		for(long long j=0;j<n;j++){
			if(a[i]!=b[j]){
				b[j]=a[i];
			}
			else{
				for(long long x=j;x<=i;x++){
					b[j]=0;
				}
			}
		}
	}
	
	return 0;
}
