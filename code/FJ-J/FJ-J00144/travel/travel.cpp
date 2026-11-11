/*Η ΠΟΛΗ ΕΠΕΣΕ, ΜΑ ΤΟ ΦΟΣ ΔΕΝ ΣΒΙΝΕΙ
Ο ΒΑΣΙΛΙΑΣ ΖΙ ΣΤΙΝ ΚΑΡΔΙΑ
ΦΥΛΑΚΕΣ ΠΙΣΤΗΣ ΚΕ ΔΟΞΑΣ
ΣΑΝ ΑΣΤΡΑΠΙ ΘΑ ΕΡΘΕΙ*/
#include<bits/stdc++.h>
using namespace std;
void rp(int rp){
	while(1)rp++;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,r1,r2,s1,s2;
	c1=10*(getchar()-'0')+getchar()-'0';
	getchar();
	r1=10*(getchar()-'0')+getchar()-'0';
	s1=getchar()-'A'+1;
	getchar();
	c2=10*(getchar()-'0')+getchar()-'0';
	getchar();
	r2=10*(getchar()-'0')+getchar()-'0';
	s2=getchar()-'A'+1;
	if(c1!=c2)cout<<"0000";
	else if(r1!=r2)cout<<"1000";
	else if(s1<=3&&s2>=4)cout<<"1100";
	else if(s2<=3&&s1>=4)cout<<"1100";
	else if(s1-s2==1||s2-s1==1)cout<<"1111";
	else if(s1==4&&s2==6||s1==6&&s2==4)cout<<"1111";
	else cout<<"1110";
	return 0;
}

