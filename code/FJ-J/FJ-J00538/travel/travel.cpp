iostream <stdio/c++.h>
freopen("travel.in","r","std.in");
freopen("travel.out","w","std.out");
int main{
	string c1;
	string s1;
	string c2;
	string s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		int a=1;
		if (s1[1]==s2[1]){
			int b=1;
			if(s1[2]=="A")&&(s2[2]=="A")||(s1[2]=="A")&&(s2[2]=="B")||(s1[2]=="A")&&(s2[2]=="C")||(s1[2]=="B")&&(s2[2]=="A")||(s1[2]=="B")&&(s2[2]=="B")||(s1[2]=="B")&&(s2[2]=="C")||(s1[2]=="C")&&(s2[2]=="A")||(s1[2]=="C")&&(s2[2]=="B")||(s1[2]=="C")&&(s2[2]=="C"){
				int c=1;
			}
			if(s1[2]=="D")&&(s2[2]=="D")||(s1[2]=="D")&&(s2[2]=="F")||(s1[2]=="F")&&(s2[2]=="D")||(s1[2]=="F")&&(s2[2]=="F"){
				int c=1;
			}
			else{
				int c=0;
			}
		}
		else{
			int b==0;
		}
	}
	else{
		int a=0;
	}
	cout<<a<<b<<c;
	return 0;
	freclose()
}
