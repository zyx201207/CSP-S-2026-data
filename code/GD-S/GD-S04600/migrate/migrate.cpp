#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
long long t,d,c,n,a[2000005],h;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		h=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				int g=0;
				long long mi=(a[j]-a[i]+d-1)/d;
				for(int k=i+1;k<=j-1;k++){
					if(a[k]-a[i]<=d&&a[j]-a[k]<=d)g++;
					if(g>2)break;
				}
				if(g==2&&mi>=2)h++;
			}
		}
		cout<<h<<endl;
	}
	return 0;
} 
