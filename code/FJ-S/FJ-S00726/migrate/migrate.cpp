#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005],o,u,c,t;
	//vector <int> o;
	//priority_queue<int> p;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	
	if(c>=11&&c<=12){
		int n,m;
		for(int ll=1;ll<=t;ll++){
			cin>>n>>m;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			int ca=a[2]-a[1];
			if(ca>=3*m||ca<2*m){
				cout<<0;
			}else{
				cout<<n-3<<endl;
			}
		}
	}else if(c==13||c==14){
		int n,m;
		for(int ll=1;ll<=t;ll++){
			cin>>n>>m;
			int star=0;
			bool un=0;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
		}
	}else{
		int n,m,o;
		for(int ll=1;ll<=t;ll++){
			cin>>n>>m;
			long long o=0;
			bool un=0;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			int j=1,k=1,u=1;
			for(int i=1;i<=n;i++){
				while(a[j+1]-a[i]<=m&&j<=n){
					j++;
				}
				
				while(a[j-2]+m>=a[k]&&k<n){
					k++;
				}k--,k=max(i+2,k);
				u=k;
				while(a[j-1]+m<=a[u+1]){//cout<<o<<" ll "<<a[j-1]+m<<" ll "<<a[u+1]<<endl;
					o++;
					if(u+1>n){
						break;
					}
					u++;
				}u--;
				
			}
			cout<<o<<endl;
		}
	}
} 
/*
5 5
 1 2 4 8 9
 */
