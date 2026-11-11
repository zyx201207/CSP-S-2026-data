#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=1e6+7;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		string x,y;
		x=s2[0]+s2[1],y=s4[0]+s4[1];
		if(s2[2]=='F'){
			s2[2]='E';
		}
		if(s4[2]=='F'){
			s4[2]='E';
		}
		if(x==y){
			if(((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
			&&(s4[2]=='A'||s4[2]=='B'||s4[2]=='C'))||
			((s2[2]=='D'||s2[2]=='E')&&
			(s4[2]=='D'||s4[2]=='E'))){
				if(abs((ll)s2[2]-s4[2])==1){
					cout<<1111<<endl;
				}
				else{
					cout<<1110<<endl;
				}
			}
			else{
				cout<<1100<<endl;
			}
		}
		else{
			cout<<1000<<endl;
		}
	}
	else{
		cout<<"0000"<<endl;
	}
	return 0;
}
