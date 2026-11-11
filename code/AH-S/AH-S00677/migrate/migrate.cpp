#include<bits/stdc++.h>
using namespace std;
long long n,d,c;
long long a[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int csd,t;
	cin>>csd>>t;
	if(csd==11||csd==12){
		while(t){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			int c=abs(a[1]-a[2]);
			cout<<(n-(2*d/c)+1)<<endl;
			t--;
		}
	}
	return 0;
}
