#include<bits/stdc++.h>
using namespace std;
#define ll long long

string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000"; 
	}else{
		cout<<1;
		string hang1,hang2;
		hang1=hang1+s1[0]+s1[1];
		hang2=hang2+s2[0]+s2[1];
		char lie1=s1[2],lie2=s2[2];
		if(hang1==hang2){
			cout<<1;
		}else{
			cout<<"000";
			return 0;
		}
		if((lie1<='C' && lie2<='C') || (lie1>='D' && lie2>='D')){
			cout<<1;
		}else{
			cout<<"00";
			return 0;
		}
		if(abs(lie1-lie2)==1){
			cout<<1;
		}else{
			cout<<0;
		}
	}
}
