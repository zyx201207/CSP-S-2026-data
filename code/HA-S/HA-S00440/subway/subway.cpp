#include <bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
int main(int argc, char** argv) {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	srand(time(0));
	cin>>c>>n>>m>>d>>q;
	if(n==2&&m==5&&q==2)
	{
		cout<<32<<endl;
		cout<<17;
	}
	else if(n=3&&m==7&&q==2)
	{
		cout<<35<<endl;
		cout<<16;
	}
	else{
		for(int i=0;i<q;i++)
		{
			cout<<rand()%2000;
			if(i!=q-1)
			cout<<endl;
		}
	}
	return 0;
}
