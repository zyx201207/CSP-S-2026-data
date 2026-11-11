#include<bits/stdc++.h>
using namespace std;
char s1[5],s2[5];
long long c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","r",stdout);
	cin>>c1>>s1[1]>>s1[2]>>s1[3]>>c2>>s2[1]>>s2[2]>>s2[3];
	if(c1==c2){
		cout<<1;
		if(s1[1]==s2[1]&&s1[2]==s2[2]){
			cout<<1;
			//cout<<s1[3]<<s2[3];
			if((s1[3]=='C'&&s2[3]=='D')||(s1[3]=='D'&&s2[3]=='C')){
				cout<<"00";
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
			if((s1[3]!='C'&&s2[3]!='D')||(s1[3]!='D'&&s2[3]!='C')){
				cout<<1;
					if(s1[3]-1==s2[3]||s1[3]==s2[3]-1){
						cout<<1;
					}
					else{
						cout<<0;
					}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{cout<<"0000";}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

