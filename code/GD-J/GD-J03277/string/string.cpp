#include<bits/stdc++.h>
using namespace std;
string S;
struct str{
	long long int a;
	string c;
};
long long int temp=0;
vector<str> p;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	long long t;
	cin>>t;
	while(t--)
	{
		long long int x;
		string y;
		cin>>x>>y;
		p.push_back({x,y});
	}
	long long int tp=p.size();
	for(int i=0;i<tp;i++)
	{
		for(int j=tp-1;j>=0;j--)
		{
			if(i==j)
			{
				cout<<temp;
				fclose(stdin);
				fclose(stdout);
				return 0;
			}
			if(p[i].c==p[j].c)
			{
				if(p[i].a>p[j].a)
				{
					p[i].a-=p[j].a;
					tp-=1;
				}
				else
				{
					p[j].a-=p[i].a;
					break;
				}
			}
			else
			{
				if(p[i].a>p[j].a)
				{
					p[i].a-=p[j].a;
					tp-=1;
					temp+=p[j].a;
				}
				else
				{
					p[j].a-=p[i].a;
					temp+=p[i].a;
					break;
				}		
			}
		}
		
	}
	cout<<temp;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
