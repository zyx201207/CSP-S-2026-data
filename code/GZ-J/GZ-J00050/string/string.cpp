//GZ-J00050   遵义市第53中学    龙炫宇； 

#include<bits/stdc++.h>
using namespace std;
long long a[200000050];
char b[100000050];

int main(){
	int n;
	cin>>n;
	string x;
	int cnt=0;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			x+=b[i];
			cnt++;
		}
	}
	int m=0,y=cnt-1;
	int cs=0;
	for(int i=0;i<cnt;i++){
		if(x[m]!=x[y]){
			x[y]=x[m];
			cs++;
			m++;
			y--;	
		}
		else{
			m++;
			y--;
		}
		
	}
	cout<<cs;
	
	return 0;
}
