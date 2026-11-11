#include<bits/stdc++.h> 
using namespace std;
#define fre
#define ll long long
#define ull unsigned long long
int main(){
	#ifdef fre
		freopen("travel.in","r",stdin);
		freopen("travel.out","w",stdout);
	#endif
	string c1,s1,c2,s2;//车厢 座位 车厢 座位 
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}
	else{
		cout<<1; 
		if(s1[0]!=s2[0]||s1[1]!=s2[1]){
			cout<<"000";
		}
		else{
			cout<<1;
			char c1=s1[2],c2=s2[2];
			if(c1=='F')c1='E';
			if(c2=='F')c2='E';
			if((c1<='C'&&c2>='D')||(c1>='D'&&c2<='C')){
				cout<<"00";
			}
			else{
				cout<<1;
				if(abs(c1-c2)==1)cout<<1;
				else cout<<0;
			}
		}
	} 
}
