#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool problem1,problem2,problem3,problem4;
bool P1()
{
	if(c1==c2)
	{
		return problem1=1;
	}else return problem1=0;
}
bool P2()
{
	if(problem1==0)return problem2=0;
	int number1=(s1[0]-'0')*10+s1[1]-'0';
	int number2=(s2[0]-'0')*10+s2[1]-'0';
	if(number1==number2)
	{
		return problem2=1;
	}else return problem2=0;
}
bool P3()
{
	if(problem1==0||problem2==0)return problem3=0;
	int number1=s1[2]-'A';
	int number2=s2[2]-'A';
	if(((number1>=0&&number1<=2)&&(number2>=0&&number2<=2))||((number1>=3&&number1<=4)&&(number2>=3&&number2<=4)))
	{
		return problem3=1;
	}else return problem3=0;
}
bool P4()
{
	if(problem1==0||problem2==0||problem3==0)return problem4=0;
	int number1=s1[2]-'A';
	int number2=s2[2]-'A';
	if(number1+1==number2||number2+1==number1)
	{
		return problem4=1;
	}else return problem4=0;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	cout<<P1()<<P2()<<P3()<<P4();
	return 0;
}

