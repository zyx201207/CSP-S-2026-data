#include<bits/stdc++.h>
using namespace std;

int c,t,n,d;
int ans[1000005];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(int k=1;k<=t;k++){
		
		cin >> n >> d;
		int sum=0;
		int x[2000005]={};
		for(int i=1;i<=n;i++){
			cin >> x[i];
		}
		int maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(abs(x[i]-x[j])<=d){
					sum++;
				}
			}
			if(sum>maxn){
				swap(sum,maxn);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int cnt=1;
				if(abs(i-j)>=maxn){
					cnt+=abs(i-j)/maxn;
				}
				if(cnt==2){
					ans[k]++;
				}
				
			}	
			
		}
	}
	for(int k=1;k<=t;k++){
		cout << ans[k] << endl;
	}
	

}
