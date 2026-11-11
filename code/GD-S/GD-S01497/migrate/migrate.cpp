#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+100;
long long x[maxn];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	int c,t;
	cin>>c>>t;
	while(t--){
		bool A=true,B=false,C=false;
		int n,d;
		long long ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i>=2&&x[i]-x[i-1]!=x[i-1]-x[i-2]){
				A=false;
			}
		}
		if(x[n]-x[1]<=2*d){
			B=true;
		}
		if(x[n]-x[1]<=10*d){
			C=true;
		}

		if(A){
			if(d<2*x[n]-x[n-1]){
				cout<<0;
				return 0;
			}
			int k=x[n]-x[n-1];
			int w=d/k;
			cout<<n-1-2*(w-2);
			return 0;
		}
		if(B){
			int k=x[n]-x[1];
			int w=d/k;
			if(k<d)
			cout<<0;
			else{
				cout<<n/2;
			}
			return 0;
		}
		if(C){
		cout<<0;
		return 0;	
		}
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				int ansl=0;
				if(x[j]-x[i]>2*d){
					continue;
				}
				for(int k=i;k<=j;k++){
					if(x[j]-x[i]<=2*d&&x[j]-x[i]>d)
					if(x[k]-x[i]<=d&&x[j]-x[k]<=d){
						ansl++;
					}
				}
				if(ansl==2){
					ans++;
				}
			}
		}
		
		cout<<ans;
	}
	return 0;
}
