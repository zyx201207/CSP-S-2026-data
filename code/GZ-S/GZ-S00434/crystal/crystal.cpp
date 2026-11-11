//GZ-S00434 北京师范大学贵阳附属中学 邹骐骏 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin >>n>>m;
	long long a[n+1];
	int ans=0;
	for(int i=1;i<=n;i++){
		cin >>a[i];
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<i;j++){
			int k=m,op=1;
			for(int l=j;l<=i;l++){
				if(k<0){
					break;
				}
				if(l==i){
					if(op>ans){
						ans=op;
					}
				}
				k-=a[i]-a[l];
				op++;
			}
		}
	}
	cout <<ans;
}
