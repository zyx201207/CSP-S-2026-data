#include<bits/stdc++.h>
using namespace std;
int n,c[200006],q=0;
string a="",b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i]>>b;
		for(int j=1;j<=c[i];j++){
			a=a+b;
		}
	}
	int d=a.size();
	for(int i=0;i<d/2;i++){
		if(a[i]!=a[d-i-1]){
			q++;
		}
	}
	cout<<q;
	return 0;
}
