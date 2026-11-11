#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout)
	int c,t;
	cin>>c>>t;
	int o[t];
	for(int w=0;w<t;w++){
	
		int n,d;
		cin>>n>>d;
	
		int x[n],g,h;
		for(int i=0;i<n;i++){
			cin>>x[i];
		}
		while(1){
			if(max(x[n-1]-x[h],0-x[n-1]+x[h])>=d){
				g++;
				o[w]=max(x[n-1]-x[h],0-(x[n-1]-x[h]))-d;
				break;
			}
				
			else if(max(x[n-1]-x[h],0-(x[n-1]-x[h]))<=d){
				g++;
				h=h+d;
			}
			else{
				h=h+d;
			}
		}
		
	}
	for(int i=0;i<t;i++){
			cout<<o[i]<<endl;
		}
	return 0;
}
