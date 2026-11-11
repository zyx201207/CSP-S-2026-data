#include<bits/stdc++.h>
using namespace std;
char a,b,c,d,e,f;
int main(){
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout); 	
	cin>>e>>f>>c>>d;
	a=e;b=f;
	if(e=='01'&&c =='01'||e=='02'&&c =='02'||e=='03'&&c =='03'||e=='04'&&c =='04'||e=='05'&&c =='05'||e=='06'&&c =='06'||e=='07'&&c =='07'||e=='08'&&c =='08'||e=='09'&&c =='09'||e=='10'&&c =='10'||e=='11'&&c =='11'||e=='12'&&c =='12'||e=='13'&&c =='13'||e=='14'&&c =='14'||e=='15'&&c =='15'||e=='16'&&c =='16'||e=='17'&&c =='17'){
		if(b/10==d/10){
			if(a%10=='A'&&b%10=='B'||a%10=='B'&&b%10=='C'||a%10=='D'&&b%10=='F'||a%10=='B'&&b%10=='A'||a%10=='C'&&b%10=='D'||a%10=='F'&&b%10=='D'){
				a=e;b=f;
				cout<<"1111";
			}else if(a%10=='C'||b%10=='D'){
				a=e;b=f;
				cout<<"1110";
			}
		}else if(b/10!=d/10){
				a=e;b=f;
				cout<<"1100";
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
