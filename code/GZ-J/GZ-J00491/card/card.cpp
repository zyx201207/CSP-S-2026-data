//GZ-J00491 遵义市第十九中学 陈昱昊 
#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long arr[10000004];
long long t[100004];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>arr[i];
	}
	long long op = 1;
	for(int i = 1;i<=n;i++){
		int u[1004] = {0};
		int st = 0;
		for(int j = op;j<=n;j++){
			if(j == op){
				u[st++] = arr[j];
			}else{
				int xy = 0;
				for(int z = 0;z<st;z++){
					if(arr[j] == u[z]){
					
						xy = 1;
					
					}
					if(xy == 1){
						u[z] = 0;
					}
				}
				u[st++] = arr[j];
			}
		}
		for(int z = 0;z<st;z++){
			t[u[z]]++;
		}
		op++;
	}
	for(int i = 1;i<=m;i++){
		cout<<t[i]<<" ";
	}
}
