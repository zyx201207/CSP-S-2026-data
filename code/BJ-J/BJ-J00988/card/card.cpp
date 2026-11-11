#include<iostream>
#include<stack>
using namespace std;

const int N = 100010;
int n, m;
int a[N];
stack<int> st;

int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    int card[100010] = {0};
    bool flag[100010] = {false};
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int flg = 1;
    while(flg < n)
    {
       for(int i = flg; i <= n; i++)
       {
           if(flag[a[i]] == true)
           {
               while(st.top() != a[i] && !st.empty())
               {
                   st.pop();
               }
               if(!st.empty())
               {
                   st.pop();
               }
           }
           st.push(a[i]);
           flag[a[i]] = true;

       }
       for(int i = 1; i <= st.size(); i++)
       {
           card[st.top()]++;
           st.pop();
       }
       while(!st.empty())
       {
           st.pop();
       }
       flg++;
    }
    for(int i = 1; i <= m; i++)
    {
        cout <<card[i]<< " ";
    }
    return 0;
}
