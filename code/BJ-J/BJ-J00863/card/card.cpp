#include <iostream>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;
stack <int> st;
int a[500005], f1[300005], f2[300005];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    for(int i = 1; i <= n; i ++)
    {
        //cout << "round " << i << endl;
        memset(f1, 0, sizeof f1);
        for(int j = i; j <= n; j ++)
        {
            if(f1[a[j]] == 0)
            {
                //cout << "push " << a[j] << endl;
                st.push(a[j]);
                f1[a[j]] ++;
            }
            else
            {
                //cout << "push " << a[j] << endl;
                while(st.top() != a[j])
                {
                    //cout << "pop " << st.top() << endl;
                    f1[st.top()] --;
                    st.pop();
                }
            }
        }
        while(!st.empty())
        {
            //cout << st.top() << " ";
            f2[st.top()] ++;
            st.pop();
        }
        //cout << endl;
    }
    for(int i = 1; i <= m; i ++)
    {
        cout << f2[i] << " ";
    }
    return 0;
}