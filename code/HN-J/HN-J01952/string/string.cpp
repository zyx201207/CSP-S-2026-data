#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,e=0,k=0,n=0;
	
	cin>>a;
	int b[a+5];
	char c[a+5];
	string d;
	for(int i=0;i<a;i++){
		cin>>b[i]>>c[i];
		for(int j=0;j<b[i];j++){
			d=d+c[i];
		}
	}
	e=d.size();
	k=e/2;
	for(int y=0;y<k;y++){
		if(d[y] != d[e-1]){
			n++;
		}
		e=e-1;
	}
	cout<<n;
	return 0;
}
