#include <bits/stdc++.h>
using namespace std;

int main()
{
    //stack <char>ss;
    ifstream ifs;
    ofstream ofs;
    ifs.open("string.in");
    ofs.open("string.out");
    int n;
    ifs>>n;
    int length[n];
    char chars[n];
    for (int i=0; i<n; i++)
    {
        ifs>>length[i]>>chars[i];
    }
    long long cnt=0;
    int sp=0;
    int ep=n;
    //cout<<n;
    for (int i=0; i<n; i++)
    {
        cout<<i;
        if (length[sp]==0)
        {
            sp++;
        }
        if (length[ep-1]==0)
        {
            ep--;
        }
        //cout<<chars[i]<<'|'<<chars[n-i-1]<<endl;
        if ((chars[sp]!=chars[ep-1]))
        {
            if (abs(length[sp]-length[ep-1])!=0)
            {
                //cnt+=abs(length[sp]-length[ep-1]);
                if(length[sp]-length[ep-1]>=0)
                {
                    cnt+=length[ep-1];
                    length[sp]=length[sp]-length[ep-1];
                    length[ep-1]=0;
                    cout<<'a';

                }
                else
                {
                    cnt+=length[sp];
                    length[ep-1]=length[ep-1]-length[sp];
                    length[sp]=0;
                    cout<<'b';

                }
            }
            else
            {
                cnt+=length[sp];
                length[sp]=0;
                length[ep-1]=0;
                cout<<'c';
            }
        }
        else
        {
            if(length[sp]-length[ep-1]>=0)
            {
                //cnt+=length[ep-1];
                length[sp]=length[sp]-length[ep-1];
                length[ep-1]=0;

            }
            else
            {
                //cnt+=length[sp];
                length[ep-1]=length[ep-1]-length[sp];
                length[sp]=0;
            }
        }
    }
    ofs<<cnt;
}
