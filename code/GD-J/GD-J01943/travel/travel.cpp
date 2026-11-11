#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char c1[20],s1[20],c2[20],s2[20];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if((c1[0]!=c2[0]&&c1[1]!=c2[1])||(c1[0]==c2[0]&&c1[1]!=c2[1])){
		cout<<"0000"<<endl;
		return 0;
	}
	cout<<1;
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<1;
		if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')){
			cout<<11<<endl;
			return 0;
		}else{
			if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')){
				cout<<10<<endl;
				return 0;
			}else{
				if(((s1[2]=='A'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='A'))||((s1[2]=='A'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='A'))){
					cout<<"00"<<endl;
					return 0;
				}else{
					if((s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')){
						cout<<11<<endl;
						return 0;
					}else{
						if(((s1[2]=='B'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='B'))||((s1[2]=='B'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='B'))){
							cout<<"00"<<endl;
							return 0;
						}else{
							if(((s1[2]=='C'&&s2[2]=='D')||(s1[2]=='D'&&s2[2]=='C'))||((s1[2]=='C'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='C'))){
								cout<<"00"<<endl;
								return 0;
							}else{
								if(((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D'))){
									cout<<11<<endl;
									return 0;
								}
							}
						}
					}
				}
			}
		}
	}else{
		cout<<"000"<<endl;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
