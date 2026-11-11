#include<bits/stdc++.h>
using namespace std;	
int main(){
	freopen("travel.in",'r',stdin);
	freopen("travel.out",'w',stdout);	
	string c1,s1,c2,s2,pai1,pai2,result;
	pai1 = s1[0]+s1[1];
	pai2 = s2[0]+s2[1];
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
		result = result + '1';
	else{
		result = result + '0'+'0'+'0'+'0';
		cout<<result;
		return 0;
	}
	if(pai1==pai2)
		result = result + '1';
	else{
		result = result + '0'+'0'+'0';
		cout<<result;
		return 0;
	}
	if(c1[2]==c2[2])
		result = result + '1';
	else{
		result = result +'0'+'0';
		cout<<result;
		return 0;
	}
	if(s1[2]+1==s2[2]||s2[2]-1==s1[2])
		result = result + '1';
	else{
		result = result + '0';
	}
	cout<<result;
	return 0;
}
