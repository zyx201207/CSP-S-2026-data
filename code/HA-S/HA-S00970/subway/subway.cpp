#include <bits/stdc++.h>
using namespace std;
const int N=5e18+1;
int c,n,m,d,q;
int s[10000000000000],a[1000000000000000],b[1000000000000];
void sum(int a,int b){
	int x,y;
	x= a[1]+a[x];
	y=b[1]+b[2]+b[y];
} 

int main(){
	int h=0,l,g;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<=m;i++){
		cin>>s[N];
	}
	for(int i=0;i<=n;i++){
		cin>>a[N];
	}
	for(int i=0;i<=n;i++){
		cin>>b[N];
	}
	for(int i=0;i<=n+2;i++){
		cin>>l;
	}
	for(int i=0;i<=n+2;i++){
		cin>>g;
	}
	h=sum(l,g);
	cout<<h<<endl;
	return 0;
}
