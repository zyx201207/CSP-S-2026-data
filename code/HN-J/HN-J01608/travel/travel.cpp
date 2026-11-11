#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);//freopen
	freopen("travel.out","w",stdout);
	string ca,sa,cb,sb;
	cin>>ca>>sa>>cb>>sb;
	if(ca==cb){
		
		int a=(sa[0]-'0')*10+sa[1],b=(sb[0]-'0')*10+sb[1];
		if(a==b){
			int n=sa[2]-'A';
			int m=sb[2]-'A';
			if(n<=2&&m<=2||n>2&&m>2){
				if(n+1==m||n-1==m){
					cout<<"1111";
				}
				else{
					cout<<"1110";
				}
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
} 
 
