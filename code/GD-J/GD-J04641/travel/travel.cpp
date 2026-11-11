#include<bits/stdc++.h>
using namespace std;
string L,l,R,r;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>L>>l>>R>>r;
	if(L==R){
	cout<<1;
		if(l[0]=r[0]&&l[1]==r[1]){
			cout<<1;
			if((r[2]<='C'&&l[2]<='C')||(r[2]+l[2]-'D'=='E')){
				cout<<1;
				if(abs(r[2]-l[2]==1)cout<<1;
				else cout<<0;
			}
			else cout<<00;
		}
		else cout<<000;
		}
	else cout<<0000;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
