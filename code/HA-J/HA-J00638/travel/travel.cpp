#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r","stdin"                         );
freopen("travel.out","w","stdout");
	int a[100],b[100],c[5]={0},n,A=1,B=2,C=3,D=4;
	cin>>n;
	for(int i=1;i<=15;i++){
			if(a[i]==b[i]){
				c[0]=c[0]+1;
					}
				else{
					c[0]=c[0]+0;
				}
			
		for(int j=1;j<=6;j++){
			if(a[j]==b[j]&&a[i]==b[i]){
				c[1]=c[1]+1;
					}
				else{
					cout<<c[1]+0;
				}
			
		
	for(int k=1;k<=5;k++){
			if(a[i]==b[i]&&a[j]==b[j]&&k<=3&&a[k]==b[k-1]||a[k]==b[k+1]){
				c[2]=c[2]+1;
				c[3]=c[3]+1;
			}
			else if(a[i]==b[i]&&a[j]==b[j]&&k>3&&k<=5&&a[k]==b[k-1]||a[k]==b[k+1]){
					c[2]=c[2]+1;
					c[3]=c[3]+1;
			}
			else{
					c[2]=c[2]+0;
						c[3]=c[3]+0;
			}
}
}
}
for(int i=1;i<=4;i++){
	cout<<c[i];
}
		

	fclose(stdin);
	fclose(stdout);
	
	
	
}

