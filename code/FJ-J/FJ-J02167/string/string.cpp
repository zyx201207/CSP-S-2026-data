#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,c[200000],e=0,f=0,sc=0,h=0;
	cin>>a;
	string d,l;
	for(int i=0;i<a;i++){
		cin>>c[i]>>d;
		for(int j=0;j<c[i];j++){
			l[e+j]=d[0];
			e++;
		}
	}
	f=e;
	//rp++
	for(int i=0;i<e/2;i++){
		if(l[i]!=l[f]){
			sc++;
		}
		f--;
	}
	cout<<sc;
	return 0;
}
