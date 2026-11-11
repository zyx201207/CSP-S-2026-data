#include<bits/stdc++.h> 

using namespace std;

int c1,c2;
string s1,s2;

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			cout<<1;
			char a=s1[2],b=s2[2];
			if(a>b){
				int x=int(a-b);
				if(x==1){
					if(a!='D'){
						cout<<11;
					}
					else{
						cout<<"00";
					}
				}
				else{
					if(a=='C'){
						cout<<10;
					}
					else{
						cout<<"00";
					}
				}
			}
			else{
				int x=int(b-a);
				if(x==1){
					if(b!='D'){
						cout<<11;
					}
					else{
						cout<<"00";
					}
				}
				else{
					if(b=='C'){
						cout<<10;
					}
					else{
						cout<<"00";
					}
				}
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
