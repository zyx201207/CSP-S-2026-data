#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,yid1="01",yid2="16";
int sum,res;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<3;i++){
		if(s1[i]==s2[i]&&i<2){
			sum++;
		}
	}
	res=abs(int(s1[2])-int(s2[2]));	
	if((c1!="01"&&c1!="16")&&((c2!="01"&&c2!="16")&&c1==c2)){
		cout<<1;
		if(sum==2){
			cout<<1;
			if(((s1[2]<='C'&&s1[2]>='A')&&(s2[2]<='C'&&s2[2]>='A'))||((s1[2]<='F'&&s1[2]>='D')&&(s2[2]<='F'&&s2[2]>='D'))){
				cout<<1;
				if(res==1&&((s1[2]!='C'&&s2[2]!='D')||(s2[2]!='C'&&s1[2]!='D'))){
					cout<<1;
				}
				else cout<<0;
			}
		    else cout<<"00";
		}
		else {
			cout<<"000";
		}
	}
	else {
		cout<<"0000";
	}
	return 0;
}
