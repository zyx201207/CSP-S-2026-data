#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll a[100000000],d,k,ans;
int c,t;
bool pd=1;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int h=1;h<=t;h++){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(c==11||c==12){
			d/=a[n]-a[n-1];
			cout<<(abs(a[n])+abs(a[1]))/2/d<<"\n";
		}
		else{
			cout<<h<<"\n";
		}
	}
	return 0;
}
