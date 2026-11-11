#include<bits/stdc++.h>
#include<time.h>
using namespace std;

int last=1793442602;

int main()
{
    int tmp;
    while(1)
    {
        int t=time(0);
        if(t!=tmp)
        {
            // cout<<"距离考试及结束还有：";
            int minu=(last-t)/60;
            int sec=(last-t)%60;
            cout<<minu<<"分"<<sec<<"秒"<<"\n";
            // cout<<t<<"\n";
            tmp=t;
        }   
    }
    return 0;
}