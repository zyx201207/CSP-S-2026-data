#include<bits/stdc++.h>

using namespace std;

string c1,s1,c2,s2;int sa,sb;

int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	cin>> c1 >> s1 >> c2 >> s2;
	int i1=0,i2=0;//³µÏáºÅ 
	i1=(c1[0]-'0')*10+c1[1]-'0';
	i2=(c2[0]-'0')*10+c2[1]-'0';
	int seat1=0,seat2=0;//×ùÎ»ÅÅ 
	seat1=(s1[0]-'0')*10+s1[1]-'0';
	seat2=(s2[0]-'0')*10+s2[1]-'0';
	
	sa=s1[2]-'A'+1;sb=s2[2]-'A'+1;
	if(i1==i2){
		cout << 1;
	}
	else{
		cout << 0;
		cout << 0;
		cout << 0;
		cout << 0;
		return 0;
	}
	
	if(seat1==seat2){
		cout << 1;
	}
	else{
		cout << 0;
		cout << 0;
		cout << 0;
		return 0;
	}
	
	if(sa<=3 && sb<=3){
		cout << 1;
	}
	else if(sa>=4 && sb>=4){
		cout << 1;
	}
	else{
		cout << 0;
		cout << 0;
		return 0;
	}
	
	if(sa==4){
		sa+=1;
	}
	if(sb==4){
		sb+=1;
	}
	int zh=abs(sa-sb);
	if(zh!=1 || seat1!=seat2){
		cout << 0;
	}
	else{
		cout << 1;
	}
    return 0;
}

