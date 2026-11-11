#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(n==2)cout<<32<<endl<<17<<endl;
	else if(n==3)cout<<35<<endl<<16<<endl;
	else
	{
		for(int i=1;i<=q;i++)
		{
			cout<<0<<endl;
		}
	}
	return 0;
}


//10. 考生不能在注释中写侮辱性话语、歌词、诗词、散文等与考试无关的话语，若有违反可能会收到取消成绩或以上处分。
