#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d,sum=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];			
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]>d&&a[j]-a[i]<2*d) sum++;
			}
		}
		cout<<sum<<endl;
	}
	
	
	
	return 0;
}
