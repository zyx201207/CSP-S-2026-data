#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2)
    {
        cout << "1";
        if(s1[0]==s2[0]&&s1[1]==s2[1])
        {
            cout << "1";
            char w1=s1[2],w2=s2[2];
            if((w1=='A'&&w2=='B')||(w1=='B'&&w2=='A')||(w1=='C'&&w2=='B')||(w1=='B'&&w2=='C')||(w1=='D'
                &&w2=='F')||(w1=='F'&&w2=='D'))
            {
                cout << "11";
            }
            else if((w1=='A'&&w2=='C')||(w1=='C'&&w2=='A'))
            {
                cout <<"10";
            }
            else
            {
                cout << "00";
            }
        }
        else
        {

            cout << "000";
        }

    }
    else
    {

        cout << "0000";
    }
    fclose(stdin);
    fclose(stdout);
return 0;
}
