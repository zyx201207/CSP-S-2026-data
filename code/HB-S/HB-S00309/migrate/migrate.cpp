#include<iostream>
#include<vector>
#include<set>
#include<string>
using namespace std;
int main()
{
    long long c,t,c1,t1;
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {




        long long n,d,n1;
        vector<int> lis;
        vector<int> lis1;
        set<int> st;
        cin>>n>>d;
        if(d%2==0){
            if(n%2==0){
                n1=n+1;

            }
        }
        for(int a=1;a<=n;a++)
        {
            long long num;
            cin>>num;
            lis.push_back(num);//lis{ok}

        }
        for(int a1=0;a1 <= n1-1;a1=a1+d)
        {
            st.insert(lis[a1]);
            c1=n-st.size();
            lis.push_back(c1);

        }






















    }
    for{int aws=1;aws<}
    return 0;
}

