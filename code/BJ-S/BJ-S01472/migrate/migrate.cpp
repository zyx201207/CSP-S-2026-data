#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,a[500001]={};
 	cin>>c>>t;
	while(t--){
		int e,f;
		cin>>e>>f;
		for(int b=1;b<=e;b++){
			cin>>a[b];
		}
		int ans[501][501]={};
		for(int  b=1;b<=e;b++){
			for(int z=a[e];z>=f;z--){
				for(int m=a[e]-1;m>=a[2];m--){
					if(m-b<=f&&m+f<=z){
						ans[b][z]++;
					}
				}
			}
		}
		int cnt=0;
		for(int b=1;b<=e;b++){
			for(int z=1;z<=e;z++){
				if(ans[b][z]==2){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}