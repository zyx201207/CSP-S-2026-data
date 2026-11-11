#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[10086];
string z[10086];
string x[10086];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	ll j=0;
	cin>>n;
	for(int i=0;i<n;i++){
		
		cin>>a[i];
		cin>>z[i];
		
		while(i>=0){
			x[j]=z[i];
			j++;	
		}	
	}
	for(int y=j;y>=0;y--){
		cout<<x[y];
	}
}
