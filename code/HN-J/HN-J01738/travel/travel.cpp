#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel2.in","r",stdin);
		freopen("travel.out","w",stdout);
		string ra,rb;
		int a,b;
		cin>>a>>ra>>b>>rb;
		if(a==b){
			if(ra[0]==rb[0]&&ra[1]==rb[1]){
				if(ra[2]=='D'||ra[2]=='F'){
				if(rb[2]=='D'||rb[2]=='F'){
					cout<<"1111";
						return 0;
				}else{
					cout<<"1100";
					return 0;
				}
			}else{
				if(rb[2]!='D'||rb[2]!='F'){
					if(ra[2]=='A'&&rb[2]=='B'){
					cout<<"1111";
						return 0;
				}
				if(ra[2]=='a'&&rb[2]=='b'){
					cout<<"1111";
					return 0;
				}
				if(ra[2]=='b'&&rb[2]=='a'){
					cout<<"1111";
					return 0;
				}
				if(ra[2]=='b'&&rb[2]=='c'){
					cout<<"1111";
					return 0;
				}
				if(ra[2]=='c'&&rb[2]=='b'){
					cout<<"1111";
					return 0;
				}
			}else{
				cout<<"1100";
				return 0;
		     	}
		     }
	         }else{
			cout<<"1000";
	 		return 0;
		}
		cout<<"1000";
	return 0;
    }
  cout<<"0000";
	return 0;
}

