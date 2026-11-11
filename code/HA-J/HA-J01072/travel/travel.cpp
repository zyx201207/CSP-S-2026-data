#include<bits/stdc++.h>

using namespace std;
string li_s1,li_s2,li_c1,li_c2;
int li_a=0,li_b=0;
	char li_a1,li_b1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>li_c1>>li_s1>>li_c2>>li_s2;
	//cout<<li_s1<<" q ";
	if(li_c2==li_c1)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	
	for(int i=0;i<li_s1.size();i++){
		if(isdigit(li_s1[i])){
			li_a*=10;
			li_a+=li_s1[i]-'0';
			
		}
		else {
			li_a1=li_s1[i];
		}
	}
	
	for(int i=0;i<li_s2.size();i++){
		if(isdigit(li_s2[i])){
			li_b*=10;
			li_b+=li_s2[i]-'0';
			
		}
		else {
			li_b1=li_s2[i];
		}
	}
	//cout<<" f"<<li_a<<" "<<li_b<<" "<<li_a1<<" "<<li_b1<<" qq ";
	if(li_a==li_b){
		cout<<1;
		if((li_a1 <='C' && li_b1<='C') || (li_a1 >'C' && li_b1>'C')){
			cout<<1;
		}
		else cout<<0;
	}
	else{
		cout<<0<<0;
	}
	//cout<<"P";
	//if((li_a1 <='C' && li_b1<='C') || (li_a1 >'C' && li_b1>'C')){
	//	cout<<1;
	//}
	//else {
	//	cout<<0;
	//}
	//cout<<" "<<li_a1<<" "<<li_b1<<" ";02 02B 02 01A
	if(abs((long long)(li_a1-li_b1))==1 ){
		if(li_a1=='C' && li_b1=='D'||li_a!=li_b){
		cout<<0;
	}
	else if(li_a1=='D' && li_b1=='C'){
		cout<<0;
	}
	else {
		cout<<1;
	}
	}
	else cout<<0;
	return 0;
}
