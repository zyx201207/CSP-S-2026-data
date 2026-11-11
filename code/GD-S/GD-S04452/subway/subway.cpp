#include <iostream>
using namespace std;

int c,n,m,d,p;
int tim[500005];
int a[505][500005];
int atim[505][500005];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	cin>>c>>n>>m>>d>>p;
	for(int i=0;i<m;i++)
	{
		cin>>tim[i];
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
