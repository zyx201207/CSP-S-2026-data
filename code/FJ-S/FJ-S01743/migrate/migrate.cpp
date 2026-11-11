#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long n,d,x[200005],z=1;
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>x[i];
			if(x[i]>z){z=abs(z*x[i]);}
			cout<<z;
		}
		z=abs(z-(n*d));
		cout<<z<<endl;
		return 0;
	}
}
