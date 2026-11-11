#include <bits/stdc++.h>
using namespace std; 
struct Data
{
	int num;
	char zm;
};
int main() {
		ifstream fin;
		ofstream fout;
		fin.open("string.in",ios::in);
		fout.open("string.out",ios::out);
		int n=0;
		fin>>n;	
		if(n==1)
		{
			fout<<0; 
			return 0;
		}
		if(n<=10)
		{
		    int sum=0;//int
			vector<Data> data(n+1,Data()) ;
			for(int i=1;i<=n;i++)
			{
				fin>>data[i].num;
				fin>>data[i].zm;
				sum+=data[i].num;
			}
			vector<char> ls(sum+1,0);
			int zs=0;//int
			for(int i=1;i<=n;i++){
				for(int j=1;j<=data[i].num;j++)
				{
					zs++;
					ls[zs]=data[i].zm;
				}
			}
			int m=sum/2;//int
			int jg=0;//int
			for(int i=1;i<=m;i++)//int
			{
				int r=n-i+1;
				if(ls[i]==ls[r])
				{
					continue;
				}
				else
				{
					jg++;
				}
			}
			fout<<jg;
			return 0;
		}
		else 
		{
			long long sum=0;//int
			vector<Data> data(n+1,Data()) ;
			for(int i=1;i<=n;i++)
			{
				fin>>data[i].num;
				fin>>data[i].zm;
				sum+=data[i].num;
			}
			vector<char> ls(sum+1,0);
			long long zs=0;//int
			for(int i=1;i<=n;i++){
				for(int j=1;j<=data[i].num;j++)
				{
					zs++;
					ls[zs]=data[i].zm;
				}
			}
			long long m=sum/2;//int
			long long jg=0;//int
			for(long long i=1;i<=m;i++)//int
			{
				long long r=n-i+1;
				if(ls[i]==ls[r])
				{
					continue;
				}
				else
				{
					jg++;
				}
			}
			fout<<jg;
			return 0;
		}	
		return 0;
   }
