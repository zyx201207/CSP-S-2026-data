#include<bits/stdc++.h>
using namespace std;
long long a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c;//有沙用
    cin>>c;
    long long t;
    cin>>t;
    while(t--){
		long long n,m,sum=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n-2;i++){
			    int j=i+3;
				if((a[j]-a[i]<=m*2)&&(a[j]-a[i]>m)){
					bool ok=true;
						if(a[i+1]-a[i]>m||a[j]-a[j-1]>m||a[j-1]-a[i+1]>m){
							ok=false;
						}
					if(ok==true){
						sum++;
					}
				}
			
		}
		cout<<sum<<endl;
	}
}
