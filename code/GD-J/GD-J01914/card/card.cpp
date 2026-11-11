#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int a[500005],fl[500005],cnt[500005];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
    	cin >> a[i];
	}
    stack<int> st;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {

            if (fl[a[j]] == 1)
            {
                while(st.top() != a[j])
                    st.pop();
                if(!st.empty()) st.pop();
                st.push(a[j]);
            }
            else
            {
                st.push(a[j]);
                fl[a[j]] = 1;
            }
        }
        while (!st.empty())
        {
            cnt[st.top()]++;
            st.pop();
        }
        for (int k = 0; k <= n; k++)
            fl[k] = 0;
    }
    for (int i = 1; i <= m; i++)
        cout << cnt[i] << " ";
    return 0;
}
