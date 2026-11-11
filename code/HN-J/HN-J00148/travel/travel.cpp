#include <iostream>
#include <string>

using namespace std;

bool judgeSameSpace(int c1,int c2)
{
	if(c1 == c2)
		return 1;
	return 0;
}

bool judgeSameRow(string s1,string s2)
{
	if(s1[0] == s2[0] and s1[1] == s2[1])
		return 1;
	return 0;
}

bool judgeSameSide(string s1,string s2)
{
	int num1 = s1[2]-'0';
	int num2 = s2[2]-'0';
	
	if(num1<=19 and num2<=19) return 1;
	if(num1>=20 and num2>=20) return 1;
	return 0; 
}

bool judgeNear(string s1,string s2)
{
	int num1 = s1[2]-'0';
	int num2 = s2[2]-'0';
	
	if( max(num1,num2) == 22 )  //F
	{
		if(min(num1,num2) == 20) return 1;//D
		return 0;
	}
	if( max(num1,num2) == 20 ) return 0;//D
	
	if( max(num1-num2,num2-num1) == 1) return 1;//ABC
	return 0;
}

int main()
{
	int c1,c2;
	string s1,s2;
	bool judge[4];
	cin >> c1 >> s1 >> c2 >> s2;
	
	judge[0] = judgeSameSpace(c1,c2);
	judge[1] = judgeSameRow(s1,s2);
	judge[2] = judgeSameSide(s1,s2);
	judge[3] = judgeNear(s1,s2);
	
	for(int i=0;i<4;i++)
	{
		if(judge[i] == 0)
		{
			for(int j=i;j<4;j++) 
				judge[j] = 0;
			break;
		}
	}
	
	for(int i=0;i<4;i++) cout << judge[i];

	return 0;
}
