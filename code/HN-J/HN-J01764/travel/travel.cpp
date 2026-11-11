#include<bits/stdc++.h>
using namespace std;
int check[6][18];
string seat[6][18];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	char ans[4]={0000};
	for(int i=0;i<6;i++){
		for(int j=0;j<18;j++){
			check[i][j]=0;
		}
	}
	for(int i=0;i<6;i++){
		char c='A';
		if(i==1){
			char c='B';
		}
		if(i==2){
			char c='C';
		}
		if(i==3){
			for(int j=0;j<18;j++){
				seat[i][j]="000";
			}
			continue;
		}
		if(i==4){
			char c='D';
		}
		if(i=5){
			char c='E';
		}
		for(int j=0;j<18;j++){
			string s;
			if(j>=0&&j<=9){
				s=j+'0';
			}
			if(j>=10){
				s=j/10+'0';
				s=j%10+'0';
			}
			seat[i][j]=s+c;
		}
	}
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans[0]='1';
	}else{
		cout<<"0000"<<endl;
		return 0;
	}
	for(int i=0;i<6;i++){
		for(int j=0;j<18;j++){
			if(s1==seat[i][j]||s2==seat[i][j]){
				check[i][j]=1;
			}
		}
	}
	for(int i=0;i<6;i++){
		for(int j=0;j<18;j++){
			if(check[i][j]==1){
				for(int k=0;k<6;k++){
					if(check[k][j]==1&&k!=i){
						ans[1]='1';
					}
				}
				if(i>=0&&i<=2){
					for(int k=0;k<=2;k++){
						if(k==i){
							continue;
						}
						if(check[k][j]==1){
							ans[2]='1';
							if(k==i+1||k==i-1){
								ans[3]='1';
							}else{
								ans[3]='0';
							}
						}else{
							ans[2]=0;
						}
					}	
				}
			}else{
				ans[1]='0';
			}
		}
	}
	for(int i=0;i<4;i++){
		cout<<ans[i];
	}
	return 0;
}
