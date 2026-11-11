#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int s1,s2,t1,t2;
	char a,b;
	cin>>t1>>s1>>a>>t2>>s2>>b;
	if(t1==t2){
		cout<<1;
		if(s1==s2){
			cout<<1;
			if(a<'D' and b<'D'){
				cout<<1;
				if(abs(a-b)==1){
					cout<<1;
				}else{
					cout<<"0";
				}
			}else if(a>'C' and b>'C'){
				cout<<11;
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
