#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100000];
string b[100000];
string rjz(int x){
	int i=0;
	string w;
	while(x==0){
		w[i]=x%2;
		x=x/2;
	}
	reverse(w.begin(),w.end());
	return w;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		b[i]=rjz(a[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<a[3];
			return 0; 
		}
	} 
	return 0;
}

