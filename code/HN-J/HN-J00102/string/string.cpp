#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("string.in","r","stdin");
	fciose(stdin);
	int a,b,c,d=0,e=0;
	int q[1000][3];
	cin>>a;
	for(int i=1;i<=a;i++){
		for(int j=1;j<=2;j++){
			cin>>q[i][j];
		}	
	}
	for(int i=1;i<=a;i++){
		b+=q[i][1];	
	}
	c=b/2;
	if(b%2!=0){
		for(int i=1;i<=c;i++){
			for(int i=a;j>c=1;j--){
				if(q[i][2]!=q[j][2]){
					e++;
				}
			}		
		}	
	}
	cout<<e;
	fciose(stdout);
	freout("string.out","r","stdout")
	return 0;
