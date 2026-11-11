#include<bits/stdc++.h>
using namespace std;
int a,b,c=0,p=0;
const int d=1e5+5;
int q[d];
int w;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int i =0;i<a;i++){
		cin>>q[i];
		
	}
	
	while(a--){
		w=q[p];
		for(int i =0;i<b;i++){
			w&=q[p+i];
		}
		if (w>c) c=w;
		p++;
	}
	cout<<c;
	return 0;
} 
