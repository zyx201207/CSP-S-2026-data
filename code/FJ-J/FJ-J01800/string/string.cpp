#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b=0,c=0,d;
	cin>>a;
	int c1[a];
	string c2,c3;
	for(int i=0;i<a;i++){
		cin>>c1[i]>>c2[i];
		for(int j=0;j<c1[i];j++){
			c3[b]=c2[i];
			b++;
			
		}
	}
	for(int i=0;i<b/2;i++){
		if(c3[i]==c3[b-i-1]){
			c++;
		}
	}
	cout<<b/2-c;
	return 0;
}
