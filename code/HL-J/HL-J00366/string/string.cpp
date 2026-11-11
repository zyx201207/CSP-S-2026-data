#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a;
	cin>>a;
	int b[a];
	char c[a];
	for(int i=0;i<a;i++){
		cin>>b[i];
		cin>>c[i];
	}
	long long d=0;
	for(int j=0;j<a;j++){
		d=d+b[j];
	}
	char q[d]={0};
	long long e=0;
	if(d%2==0){
		e=d/2;
	}
	else{
		e=d/2;
	}
	long long t=0;
	for(int z=0;z<a;z++){
		for(int f=0;f<b[z];f++){
			q[t]=c[z];
			t++;
		}
	}
	long long h=0;
	for(int l=0;l<e;l++){
		if(q[l]!=q[d-l-1]){
			h++;	
		}
	}
	cout<<h<<endl;
	return 0;
}
