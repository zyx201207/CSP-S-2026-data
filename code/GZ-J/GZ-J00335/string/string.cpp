#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,b=0,n=0;
	cin>>a;
	int c[a];
	string d[a];
	int i=0;
	for(int j=0;j<a;j++){
		cin>>c[i-n]>>d[i-n];
		if(d[i-n]==d[i-1-n]){
			d[i-n-1]+=d[i-n];
			n++;
			i--;
		}
		i++;
	}
	int f=(a-n)/2;
	for(int j=0;j<f;j++){
		if(d[j]!=d[a-j]){
			if(c[j]>c[a-j]){
				b+=c[j];
			}else{
				b+=c[a-j];
			}
		}
	}
	cout<<b;
	return 0;
} 
