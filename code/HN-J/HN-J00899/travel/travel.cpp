#include <iostream>
using namespace std;

int r;
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    for (int i = 1,i >= 0,i++)
	{
    	r[i] = r[i] + r[i+1];
    	if (i > 0){
    		cout << "2";
		}
	}
	freclose("travel.in");
	freclose("travel.out");
	return 0;
}
