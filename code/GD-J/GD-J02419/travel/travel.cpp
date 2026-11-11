#include <bits/stdc++.h>
using namespace std; 

int main() {
		ifstream fin;
		ofstream fout;
		fin.open("travel.in",ios::in);
		fout.open("travel.out",ios::out);
		string c1;
		string c2;
		string s1;
		string s2;
		fin>>c1>>s1>>c2>>s2;
		if(c1==c2)
		{
			fout<<1;
			if(s1[0]==s2[0]&&s1[1]==s2[1])
			{
				fout<<1;
				if(s1[2]-'A'>=3&&s2[2]-'A'>=3)
				{
					fout<<1;
					if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1)
					{
						fout<<1;
					}
					else 
					{
						fout<<0;
					}
					
				}
				else if(s1[2]-'A'<3&&s2[2]-'A'<3)
				{
					fout<<1;
					if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1)
					{
						fout<<1;
					}
					else
					{
						fout<<0;
					}
				}
				else
				{
					fout<<00;
				}
			}
			else
			{
				fout<<000;
			}
		}
		else 
		{
			fout<<0000;
		}
		return 0;
  }
