#include<bits/stdc++.h>
using namespace std;
string a;
long long s=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int t=0;
	for(int i=1;i<=n;i++){
		int x;
		string y;
		cin>>x>>y;
		for(int j=0;j<x;j++){
			a+=y;
		}
		t+=x;
	}
	t--;
	for(int i=0,j=t;i<=t/2,j>t/2;i++,j--){
		if(a[i]!=a[j]){
			s++;
			cout<<i<<' '<<j<<endl;
		}
	}
	cout<<s<<'\n';
	return 0;
}
