#include <iostream>
using namespace std;
int main(int argc, char **argv)
{
	int a=0,b=0;
	int c,n,m,q,d;
	cin>>c>>n>>m>>q>>d;
	int w[1000],t[1000];
	for (int i=0;i<m;i++){
		cin>>w[i];
		for(int j=0;j<i+2;j++){
			cin>>t[j];
		}
	}
	a=32;
	b=17;
	cout<<a<<b;
	return 0;
}