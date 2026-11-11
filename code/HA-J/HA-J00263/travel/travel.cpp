#include<bits/stdc++.h>
#define ll long long
#define N 200001
using namespace std;
string a,b,sa,sb;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>sa>>b>>sb;
	if(a==b){
		cout<<1;
		if(sa[0]==sb[0]&&sa[1]==sb[1]){
			cout<<1;
			if(sa[2]>sb[2]) swap(sa[2],sb[2]);
			if(sa[2]=='A'&&sb[2]=='B') cout<<"11"<<endl;
			else if(sa[2]=='A'&&sb[2]=='C') cout<<"10"<<endl;
			else if(sa[2]=='B'&&sb[2]=='C') cout<<"11"<<endl;
			else if(sa[2]=='D'&&sb[2]=='E') cout<<"11"<<endl;
			else cout<<"00"<<endl;
		}else cout<<"000"<<endl;
	}else cout<<"0000"<<endl;
	return 0;
}
