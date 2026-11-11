#include<bits/stdc++.h>
using namespace std;
long long  c[1000000000];
char d[1000000000];
char v[1000000000];
int main(){
	freopen("string.in.txt","r",stdin);
	freopen("string.out.txt","w",stdout);
	int a;
	int num=0;
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>c[i]>>d[i];
		num+=c[i];
	}
	int e=0;
	for(int i=0;i<a;i++){
		for(int k=0;k<c[i];k++){
			v[e]=d[i];
			e+=1;

		}
	}
	int w=0;

	for(int i=0;i<num/2;i++){
		if(v[i]!=v[num-i-1]){
			w=1;

		}		
	}
	if(w==0){
		cout<<0;
	}
	return 0;
}
