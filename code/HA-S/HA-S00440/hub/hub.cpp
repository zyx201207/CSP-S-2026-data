#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	srand(time(0));
	for(int i=0;i<t;i++)
	{
		cout<<rand()%500;
		if(i!=t-1)
		cout<<endl;
	}
	return 0;
}
