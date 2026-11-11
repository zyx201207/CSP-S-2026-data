#include<bits/stdc++.h> 
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int asn=INT_MIN;
bool ok=false,ok2=false,ok3=false;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	if(n==m) ok=true;
	if(m==2) ok2=true;
	if(m==1) ok3=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		asn=max(asn,a[i]);
	}
	if(ok){
		int z=a[1];
		for(int i=1;i<=n;i++){
			z=(z&a[i]);
		}
		cout<<z;
		return 0; 
	}
	if(ok2){
		int z=INT_MIN;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				int y=(a[i]&a[j]);
				z=max(z,y);
			}
		}
		cout<<z;
		return 0;
	}
	if(ok3){
		cout<<asn;
		return 0;
	}
	
//	cout<<(n&m);
	return 0;
}
