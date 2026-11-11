#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,b;
int sum[100001];
long q[200002],mp[20002][20002];
void lucheng(){
	for(int i=0;i<n;i++){
		for(int j=n-1;j>0;j--){
			for(int z=i+1;z<j;z++){
				if(q[j]-q[i]>d){
					if(q[j]-q[z]<=d&&q[z]-q[i]<=d){
						mp[i][j]++;
					}
				}
			}
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	int w=t;
	while(t>0){
		
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>q[i];
		
			
		}
		lucheng();
		for(int i=0;i<n;i++){
			for(int j=n-1;j>0;j++){
				if(mp[i][j]==2){
					sum[t]++;
				}	
			}
		}
		t--;
	}
	for(int i=w;i>0;i--){
		cout<<sum[i]<<endl;
	}
	
	
	return 0;
}
