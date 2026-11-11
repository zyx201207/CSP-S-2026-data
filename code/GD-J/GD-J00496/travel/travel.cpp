#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,s2,c2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		string a,b,n,m;
		int x,y;
		cout<<1;
		for(int i=0;i<s1.size();i++){
			if(s1[i]>='0'&&s1[i]<='9'){
				a+=s1[i];
			}else{
				x=s1[i]-'A'+1;
			}
		}
		for(int i=0;i<s2.size();i++){
			if(s2[i]>='0'&&s2[i]<='9'){
				b+=s2[i];
			}else{
				y=s2[i]-'A'+1;
			}
		}
		int c=stoi(a);
		int d=stoi(b);
		if(c==d){
			cout<<1;
			if((x<=3&&y<=3)||(x>3&&y>3)){
				cout<<1;
				if(abs(x-y)==1){
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
