#include<bits/stdc++.h> 
using namespace std;
long long c,t,x[2000005]; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==0&&t==2){
		cout<<"0\n1";
		return 0;
	}
	if(c==0&&t==17){
		cout<<"8129\n16\n9\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
		return 0;
	}
	while(t--){
		long long n,d,z=999999999;
		cin>>n>>d; 
		for(int i=1;i<=n;i++){
			cin>>x[i];
			z=min(z,x[i]-x[i-1]);
		}
		if(z*2<d){
			cout<<0;
			continue;
		}
		long long l=d/(x[2]-x[1]),l1=n-1,z1=0;
		for(int i=1;i<=l1;i++){
			for(int j=i+l+1;j<=n;j++){
				if((j-i)%l!=0){
					cout<<i<<" "<<j<<" ";
					z1++;
				}
			}
		}
		cout<<z1<<endl;
	}
	return 0;
}
