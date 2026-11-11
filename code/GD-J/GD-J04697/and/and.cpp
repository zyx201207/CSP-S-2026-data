#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
int a[10000000];
string convert(int x){
	int t=0;
	string k;
	while(x){
		k[t++]=(x%2)+'0';
		x/=2;
	}
	string w;
	int y=t;
	for(int i=0;i<y;i--){
		w[i]=k[--t];
	}
	return w;
}
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
//	cin>>n>>m;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//	} 
	cout<<convert(10);
	return 0;
} 
