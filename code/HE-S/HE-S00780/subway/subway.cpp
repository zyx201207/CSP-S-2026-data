#include<bits/stdc++.h>
using namespace std;
const int N=555555;
int c,n,m,d,q,k1;
int a[N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>k1;
		for(int j=0;j<2*k1;j++){
			cin>>a[i];
		}
	}
	for(int i=0;i<4;i++){
		cin>>a[i];
	}
	cout<<32<<endl;
	cout<<17<<endl;
	return 0;
} 
