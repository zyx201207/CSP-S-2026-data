#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("r","string.in",stdin);
	freopen("w","string.ont",stdout);
	string QAQ="";
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int q;
		char w;
		cin>>q>>w;
		for(int j=0;j<q;j++)
		{
			QAQ=QAQ+w;
		}
	}
	int cccc=0;
	for(int i=0;i<QAQ.size()/2;i++)
	{
		if(QAQ[i]!=QAQ[QAQ.size()-1-i])
		{
			cccc+=1;
		}
	}
	cout<<cccc;
	return 0;
}
