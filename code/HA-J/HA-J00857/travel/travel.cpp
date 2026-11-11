#include <bits/stdc++.h>
using namespace std;
int c1,c2,p1,p2,l1,l2;
string s1,s2;
int main () {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<3;i++){
		if(s1[i]>='0'&&s1[i]<='9'){
			p1=p1*10+(int)(s1[i]-48);
		}else {
			l1=(int)(s1[i]-64); 
		}
	}
	for(int i=0;i<3;i++){
		if(s2[i]>='0'&&s2[i]<='9'){
			p2=p2*10+(int)(s2[i]-48);
		}else {
			l2=(int)(s2[i]-64); 
		}
	}
	if(c1==c2){
		cout<<1;
	}else {
		cout<<0;
	}
	if(c1==c2&&p1==p2){
		cout<<1;
	}else {
		cout<<0;
	}
	if(c1==c2&&p1==p2&&((l1<=3&&l2<=3)||(l1>=4&&l2>=4))){
		cout<<1;
	}else {
		cout<<0;
	}
	if(c1==c2&&p1==p2&&(((l1<=3&&l2<=3)||(l1>=4&&l2>=4)))&&abs(l1-l2)==1){
		cout<<1;
	}else {
		cout<<0; 
	}
	return 0;
}
