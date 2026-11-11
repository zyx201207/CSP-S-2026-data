#include<bits/stdc++.h>
using namespace std;
int che1,che2;
string st1,st2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>che1>>st1>>che2>>st2;
	if(che1==che2){
		cout<<1;
		if(st1[0]==st2[0] && st1[1]==st2[1]){
			cout<<1;
			int s1=st1[2]-'A',s2=st2[2]-'A';
			//cout<<s1<<" "<<s2<<endl;
			if((s1<3 && s2<3) || (s1>=3 && s2>=3)){
				cout<<1;
				if(s1-s2==-1 || s1-s2==1){
					 cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0; 
}
