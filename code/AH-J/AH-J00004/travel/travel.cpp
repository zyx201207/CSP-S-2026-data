#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string s1,s2;
string c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>c1;
	cin>>s2>>c2;
	if(s1==s2){
		cout<<1;
		string s3="",s4="";
		for(ll i=0;i<2;i++){
			s3+=c1[i];
			s4+=c2[i];
		}
		if(s3==s4){
			cout<<1;
			char p1=c1[c1.size()-1],p2=c2[c2.size()-1];
			//cout<<p1<<" "<<p2<<endl;
			if(((p1=='A'||p1=='B'||p1=='C')&&(p2=='A'||p2=='B'||p2=='C'))||((p1=='D'||p1=='F')&&(p2=='D'||p2=='F'))){
				cout<<1;
				if((char)(p1-1)==p2||char(p2-1)==p1){
					cout<<1;
				}else{
					cout<<"0";
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
