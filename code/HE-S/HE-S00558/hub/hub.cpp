#include <bits/stdc++.h>
using namespace std;
string a="It seems I won't get any scores";
string b="I can't answer these qustions";
string c="I don't know why I am there";
int u,y,n,t;
int p,g,m;
void run(int ys)
{
	cout << ys << endl;;
	int u;
	cin >> u;
	if(u==-1) return ;
	if(ys==u)
	{
		cout << "perfect" << endl;
		p++;
	} 
	else if(ys-u==1 || ys-u==-1 || ys & u>=y-4)
	{
		cout << "good" << endl;
		g++;
	} 
	else
	{
		cout << "miss" << endl;
		m++;
	}  
	t++;
}
int main()
{
	cout << "Thanks for you with playing type(v.1.0)" << endl;
	int n=1;
	while(n!=0)
	{
		cout << "number:";
		cin >> n;
		if(n==1)
		{
			for(int i=1;i<=a.size();i++)
			{
				int y=a[i];
				run(y);	
				if(u==-1) break;
			}
		}
		if(n==2)
		{
			for(int i=1;i<=b.size();i++)
			{
				int y=b[i];
				run(y);	
				if(u==-1) break;
			}
		}
		if(n==3)
		{
			for(int i=1;i<=c.size();i++)
			{
				int y=c[i];
				run(y);	
				if(u==-1) break;
			}
		}
	}
	cout << "data£º" << " perfect" << " " << p;
	cout << " " << " good" << " " << g;
	cout << " " << " miss" << " " << m << " ";
	cout << "(tolal:" << t << ")";
	return 0;
}
 
