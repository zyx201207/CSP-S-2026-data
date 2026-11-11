#include<bits/stdc++.h>
using namespace std;
string a;
int n,g=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int b;
		string c;	
		cin>>b>>c;
		for(int j=1;j<=b;j++){
			a+=c;
		}
	}
	int j=a.size()-1;
	for(int i=0;i<a.size()/2;i++){
		if(a[i]!=a[j])
			g++;
		j--;
	}
	cout<<g;
	return 0;
}
