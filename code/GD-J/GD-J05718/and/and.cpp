#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m;
bool v[N];
string a[N],b[N],x[N];
string js(){
	string r;
	
	return r;
}
string rjz(string stra){
	string strb;
	
	return strb;
}
void g(int k){
	if(k==m){
		string txt=js();
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i]==0){
			v[i]=1;
			x[k]=b[i];
			g(k+1);
			v[i]=0;
		}
	}
}
int main(){
	freopen("r","and.in",stdin);
	freopen("w","and.out",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		b[i]=rjz(a[i]);
	}
	cout<<a[n];
//	g(0);
	return 0;
}
