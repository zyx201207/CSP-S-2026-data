#include <bits/stdc++.h>
using namespace std;
int a[15];
char b[15][15];
int sum=0,ant=0,cnt=0;
char c='0';
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	for(int i=1;i<=2;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=2;i++){
		if(a[i]!=a[i-1]){
			cout<<"0000";
			return 0;
		}else{
			sum+=1000;
		}
	}for(int i=1;i<=2;i++){
		for(int j=1;j<=3;j++){
				if(c=='0'){
					c=b[i][j];
				}else{
					if(c=='F'&&b[i][j]=='D'||c=='D'&&b[i][j]=='F'||c=='A'&&b[i][j]=='B'||c=='B'&&b[i][j]=='A'||c=='B'&&b[i][j]=='C'||c=='C'&&b[i][j]=='B'||c=='A'&&b[i][j]=='C'||c=='C'&&b[i][j]=='A'){
						sum+=10;
						if(c=='F'&&b[i][j]=='D'||c=='D'&&b[i][j]=='F'||c=='A'&&b[i][j]=='B'||c=='B'&&b[i][j]=='A'||c=='B'&&b[i][j]=='C'||c=='C'&&b[i][j]=='B'){
							sum+=1;
						}else{
							cout<<1111;
							return 0;
						}
					}else{
						cout<<1110;
						return 0;
					}
				}
		}}
	cout<<sum;
	return 0;
} 
