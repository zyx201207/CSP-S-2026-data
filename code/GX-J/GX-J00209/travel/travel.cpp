#include <iostream>;
#include <string>;
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	string a,b,c,d;
	int q1 = 0,q2 = 0;
	cin >> a >> b >> c >> d;
	if(a == c)
    {
        cout <<"1";
        q1 =1;
    }
    else{
        cout <<"0";
    }

    if(b[0] == d[0] && b[1] == d[1] && q1 == 1){
        cout <<"1";
        q2 =1;
    }
    else{
        cout <<"0";
    }


    int x = 0,y = 0;
    if(b[2] == 'A' or b[2] == 'B' or b[2] == 'C')
    {
        x = 0;
    }
    else{
        x = 1;
    }
    if(d[2] == 'A' or d[2] == 'B' or d[2] == 'C')
    {
        y = 0;
    }
    else{
        y = 1;
    }

    if(x == y and q2 == 1 and q1 == 1)
    {
        cout << "1";
    }
    else
    {
        cout <<"0";
    }

    if(b[2] == 'A')
        x = 1;
    else if(b[2] == 'B')
        x = 2;
    else if(b[2] == 'C')
        x = 3;
    else if(b[2] == 'D')
        x = 8;
    else if(b[2] == 'F')
        x = 9;
    if(d[2] == 'A')
        y = 1;
    else if(d[2] == 'B')
        y = 2;
    else if(d[2] == 'C')
        y = 3;
    else if(d[2] == 'D')
        y = 8;
    else if(d[2] == 'F')
        y = 9;

    if(q1 == 1 and q2 == 1){
        if(x == y-1 or x == y+1)
        {
            cout <<"1";
        }
        else{
            cout <<"0";
        }
    }
    else{
            cout <<"0";
    }
	return 0;
}
