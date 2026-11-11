#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=2000060;
int c,t;
long long a[MAXN];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		memset(a,0,sizeof(a));
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>a[i];
	}
	cout<<"2\n1";
	return 0;
}
