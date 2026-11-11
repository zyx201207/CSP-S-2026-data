//GZ-J00662 都匀第十中学 郑杰康
#include<bits/stdc++.h>
using namespace std;
string a,a1,b,b1;
int k;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	if(a==b){
		cout<<1;
		if(a1[0]==b1[0]&&a1[1]==b1[1]){
			cout<<1;
			if(a1[2]=='A'||a1[2]=='B'||a1[2]=='C'){
				if(b1[2]=='A'||b1[2]=='B'||b1[2]=='C'){
					k=1;
					cout<<1;
				}else{
					cout<<0<<0;
				}
			}else{
				if(b1[2]=='D'||b1[2]=='F'){
					k=1;
					cout<<1;
				}else{
					cout<<0<<0;
				}	
			}
			if(k==1){
				if(int(a1[2])-1==int(b1[2])||int(a1[2])+1==int(b1[2])){
					if(a1[2]=='C'&&b1[2]=='D'){
						cout<<0;
					}else{
						cout<<1;	
					}
				}else{
					cout<<0;
				}
			}			
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

