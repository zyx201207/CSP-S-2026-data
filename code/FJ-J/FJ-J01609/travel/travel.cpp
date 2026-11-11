#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		char c=s1[2];char d=s2[2];
		if(s1[0]+s1[1]==s2[0]+s2[1]){
			cout<<1;
			if((c-'A'<=2&&d-'A'<=2)||(2<c-'A'&&c-'A'<=4&&2<d-'A'&&d-'A'<=4)){
				cout<<1;
				if(c-d==1||d-c==1)
			{cout<<1;
			}else{cout<<0;
			}
			}else{cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
