#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		cout<<"1";
		int t1,t2;
		for(int i=0;i<int(a2.size())-1;i++){
			t1=t1*10+int(a2[i]-'0');
			t2=t2*10+int(b2[i]-'0');
		}
		if(t1==t2){
			cout<<"1";
			if((a2[2]<='C'&&b2[2]<='C')||(a2[2]>='D'&&b2[2]>='D')){
				cout<<"1";
				if(int(a2[2]+1)==int(b2[2])||int(a2[2]-1)==int(b2[2])){
					cout<<"1";
					return 0;
				}
				else{
					cout<<"0";
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
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
