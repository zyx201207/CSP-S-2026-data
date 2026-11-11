#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int o=0,p=0;
	cin>>c1>>s1>>c2>>s2;
	o=s1[0]*10+s1[1];
	p=s2[0]*10+s2[1];
//	for(int i=0;i<s1.size();i++){
//		if(s1[i]>='0'&&s1[i]<='9'){
//			o=o*10+s1[i]-'0';
//		}
//	}for(int i=0;i<s2.size();i++){
//		if(s2[i]>='0'&&s2[i]<='9'){
//			p=p*10+s2[i]-'0';
//		}
//	}
	if(c1==c2){
		cout<<1;
		if(o==p){
			cout<<1;
			if( (s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C') ||( ( s1[2]=='D'||s1[2]=='F' )&&( s1[2]=='D'||s1[2]=='F' ) )){
				cout<<1;
				char c=s1[2],d=s2[2];
				if((c=='A'&&d=='B')||(c=='B'&&d=='A')||(c=='B'&&d=='C')||(c=='C'&&d=='B')||(c=='D'&&d=='F')||(c=='F'&&d=='D')){
					cout<<1;
				}else{
					cout<<"0";
					return 0;
				}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
}