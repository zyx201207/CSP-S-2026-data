#include<bits/stdc++.h>
using namespace std;
long long a,b,c[200005],d[200005],e=0,f=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>c[i];
	}
	
	for(int i=0;i<b;i++){
		for(int j=0;j<a;j++){
			if(c[j]>e){
				e=c[j];
				f=j;}
		}
		d[i]=e;
		c[f]=0;
		e=0;
		f=0;
	}
	e=d[0];
	for(int i=1;i<b;i++){
		e&=d[i];
	

	}
	cout<<e;
	return 0;
}
