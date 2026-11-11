#include <bits/stdc++.h>
using namespace std;
vector<int> v;
stack<int> s;
int a[30005];
bool isfound(int x){
	if(s.empty())return 0;
	stack<int> s1;;
	bool fl=0;
	while(!s.empty()){
		int t=s.top();
		if(t==x){
			fl=1;
		}
		s.pop();
		s1.push(t);
	}
	while(!s1.empty()){
		int f=s1.top();
		s1.pop();
		s.push(f);
	}
	return fl;
	
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,x;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&x);
		v.push_back(x);
	}
	int l=v.size();
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j<l;j++)
		{
			int k=v[j];
			if(isfound(k)){
				while(1)
				{
					if(s.top()==k)
					{
						s.pop();
						break;
					}
					s.pop();
				}	
			}
			s.push(k);
		}
		while(!s.empty()){
			a[s.top()]++;
			s.pop();
		}
	} 
	for(int i=1;i<=m;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
