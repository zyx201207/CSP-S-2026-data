#include<bits/stdc++.h>
using namespace std;
long long n,zon;
struct nadec{
	long long a;
	char s;
	bool b;
}a[200050];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		cin>>a[i].a>>a[i].s;
		zon+=a[i].a;
	}
	if(n==2){
		if(a[1].s==a[2].s){
			cout<<0;
			return 0;
		}
		else {
			cout<<max(a[1].a,a[2].a);
			return 0;
		}
	}
	cout<<zon%2;
	return 0;
} 
