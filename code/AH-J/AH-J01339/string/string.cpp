#include <bits/stdc++.h>
using namespace std;
struct t{
	long long x;
	char c;
} a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].x;
		cin>>a[i].c;
	}
	long long j=n,ans=0;
	for(long long i=1;i<=n;i++){
		if(i==j) break;
		while(a[i].x){
			if(a[i].x>=a[j].x){
				if(a[i].c!=a[j].c){
					ans+=a[j].x;
				}
				a[i].x-=a[j].x;
				a[j].x=0;
				j--;
			}
			else{
				if(a[i].c!=a[j].c){
					ans+=a[i].x;
				}
				a[j].x-=a[i].x;
				a[i].x=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
