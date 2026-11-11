#include<bits/stdc++.h>
#define ll long long
using namespace std;
void bol(bool a){
	if(a)cout<<1;
	else cout<<0;
}
string a1,b1,a2,b2;
int a,b,c,s;
bool sf=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>a2>>b2;
	bol(a1==a2);
	a=b1[0]*10+b1[1];
	b=b2[0]*10+b2[1];
	c=b1[2]-'A'+1,s=b2[2]-'A'+1;
	bol(a==b&&a1==a2);
	bol(a==b&&((c<=3&&s<=3)||(c>3&&s>3))&&a1==a2);
	if(a1==a2){
		if(a==b){
			if(c-s==1||s-c==1){
				if((c!=3&&c!=4)||(c!=4&&c!=3)){
					cout<<1;
					sf=0;
				}
			}
		}
	}
	if(sf)cout<<0;
	return 0;
}
