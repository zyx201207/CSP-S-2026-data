#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if((stoi(c1)==stoi(c2))){
		cout<<1;
		string str1="",str2="";
		for(int i=0;i<2;i++){
			str1=str1+s1[i];
			str2=str2+s2[i];
		}
		if(stoi(str1)==stoi(str2)){
			cout<<1;
			char a=s1[2],b=s2[2];
			if((a=='C'&&b=='D')||(a=='D'&&b=='C')){
				cout<<"00";
			}else{
				cout<<1;
				if(abs(int(a-b))==1)cout<<1;
				else cout<<0;
			}
		}else cout<<"000";
	}else cout<<"0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
