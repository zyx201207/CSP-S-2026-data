#include <bits/stdc++.h> 
using namespace std;
const long long N=2e5+78;
struct noge{
	long long x;
	char id;
}a[N];
long long n,n1,ans;
char c1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>n1>>c1;
		a[i].x=a[i-1].x+n1;
		a[i].id=c1;
	}
	long long j1=1,j2=n,k=(a[n].x+1)/2;
	for(int i=1;i<=k;i++){
		while(i>a[j1].x){
			j1++;
		}
		while((a[n].x+1-i)<=a[j2-1].x){
			j2--;
		}
		if(a[j1].id!=a[j2].id){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
