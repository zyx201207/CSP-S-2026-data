#include<bits/stdc++.h>
using namespace std;
int main()
{
	int add[100000] = {0};
	ifstream fin;
	fin.open("card.in",ios::in);
	ofstream fout;
	fout.open("card.out",ios::out);
	int n,m;
	fin>>n;
	fin>>m;
	for(int i = 0;i < n;i++)
	{
		fin>>add[i] ;
	}
	for(int i = 0;i < n;i++)
	{
		fout<<add[i];
	}
	return 0;
}
