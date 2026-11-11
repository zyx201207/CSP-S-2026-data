#include <bits/stdc++.h>

using namespace std;

bool is_neighbour1(char a,char b){
	if(a>='A' && a<='C' && b>='A' && b<='C')
		return true;
	if(a>='D' && a<='F' && b>='D' && b<='D')
		return true;
	return false;
}

bool is_neighbour2(int a_number,char a_type,int b_number,char b_type){
	int might1_number=a_number+1;
	char might1_type=a_type;
	int might2_number=a_number-1;
	char might2_type=a_type;
	int might3_number=a_number;
	char might3_type=a_type+1;
	int might4_number=a_number;
	char might4_type=a_type-1;
	/*
	cout<<might1_number<<' '<<might1_type<<'\n';
	cout<<might2_number<<' '<<might2_type<<'\n';
	cout<<might3_number<<' '<<might3_type<<'\n';
	cout<<might4_number<<' '<<might4_type<<'\n';
	*/
	if(b_number==might1_number && b_type==might1_type)
		return true;
	if(b_number==might2_number && b_type==might2_type)
		return true;
	if(b_number==might3_number && b_type==might3_type)
		return true;
	if(b_number==might4_number && b_type==might4_type)
		return true;
	return false;
}

int string_turn_to_int(string a){
	int n=0;
	for(size_t i=0;i<a.size();i++)
		n=(n*10)+(a[i]-'0');
	return n;
}

string c1_temp,s1_temp,c2_temp,s2_temp;
int c1=0,s1_number=0,c2=0,s2_number=0;
char s1_type='0',s2_type='0';

int main(){
	freopen("travel.in","r",stdin);//Ò»¶¨È¥×¢ÊÍ£¡ 
	freopen("travel.out","w",stdout);
	cin>>c1_temp>>s1_temp>>c2_temp>>s2_temp;
	c1=string_turn_to_int(c1_temp);
	c2=string_turn_to_int(c2_temp);
	s1_type=s1_temp[2],s2_type=s2_temp[2];
	for(size_t i=0;i<s1_temp.size()-1;i++)
		s1_number=(s1_number*10)+(s1_temp[i]-'0');
	for(size_t i=0;i<s2_temp.size()-1;i++)
		s2_number=(s2_number*10)+(s2_temp[i]-'0');
	//cout<<s1_number<<' '<<s2_number<<' ';//No Problem
	if(c1==c2)
		cout<<true;
	else
		cout<<false;
	if(c1==c2 && s1_number==s2_number)
		cout<<true;
	else
		cout<<false;
	if(c1==c2 && s1_number==s2_number && is_neighbour1(s1_type,s2_type))
		cout<<true;
	else
		cout<<false;
	if(c1==c2 && s1_number==s2_number && is_neighbour1(s1_type,s2_type) && is_neighbour2(s1_number,s1_type,s2_number,s2_type))
		cout<<true;
	else
		cout<<false;
	return 0;
}
