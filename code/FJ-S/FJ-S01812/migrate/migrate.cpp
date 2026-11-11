#include <bits/stdc++.h>
using namespace std; 
int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	
	
	while(t){
		int n,d;
		cin>>n>>d;
		static long long x[2000002];
		for(int i=0;i<n;i++){
			cin>>x[i];
			if(x[i]-x[i-1]>d){
				i--;
				n--;
			}
			
		}
		int re=0;
		for(int i=0;i<n;i++){
			for(int j=i+3;j<n;j++){
				if(x[j]-x[i]>d){
					int xx=0;
					for(int k=i;k<j-2;k++){
						if(x[k+2]-x[k]<=d && x[k+3]-x[k+1]<=d && x[k+3]-x[k]>d){
							xx++;
						}
						
					}
					if(xx==1){
						re++;
					}
				}
			}
		}
		cout<<re;
		t--;
	}
	
	return 0;
}
