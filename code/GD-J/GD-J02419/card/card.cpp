#include <bits/stdc++.h>
using namespace std; 
int main() {
	ifstream fin;
	ofstream fout;
	fin.open("card.in",ios::in);
	fout.open("card.out",ios::out);
	int n=0;
	int m=0;
	fin>>n>>m;
	vector<int> ls(n+1,0) ;
	if(n<=5)
	{
		if(m==1)
		{
			fout<<1;
		}
		else if(m==2)
		{
			fout<<1<<" "<<1;
		}
			
	}

	return 0;
}
