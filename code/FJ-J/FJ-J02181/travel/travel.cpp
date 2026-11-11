#include<bits/stdc++.h>
using namespace std;
char a[5]={'A','B','C','D','E'};
int check(string x)
{
	for(int i=0;i<=4;i++){
		if(x[2]==a[i]){
			if(i>2){
				return 1;
			}
			else{
				return 2;
			}
		}
	}
	return 2;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1.substr(0,2)==s2.substr(0,2)){
			cout<<1;
			if(check(s1)==check(s2)){
				cout<<1;
				if(abs((s1[2]-64)-(s2[2]-64))==1){
					cout<<1;
					return 0;
				}
				else{
					cout<<0;
					return 0;
				}
			}
			else{
				cout<<"00";
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	
}
