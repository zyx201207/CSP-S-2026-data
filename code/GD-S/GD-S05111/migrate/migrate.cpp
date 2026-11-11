#include<iostream>
using namespace std;
const int N=500001;
long long a[N];
long long d;
int n,sum=0,c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	int s[t+1];
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n-3;i++)
			if(a[i+3]-a[i]>d && a[i+3]-a[i]<d*2)
				if(a[i+2]-a[i]<=d && a[i+3]-a[i+1]<=d) sum++;
		s[i]=sum;
	}
	for(int i=1;i<=t;i++) cout<<s[i]<<endl;
	return 0;
}
