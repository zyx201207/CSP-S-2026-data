#include <bits/stdc++.h>
using namespace std;


bool is_wen(string a)
{
    int a_len = a.size();
    string tmp = "";
    for (int i = a.size() - 1;i>=0;i--)
    {
        tmp = tmp + a[i];
    }
    if (tmp == a)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n;
    int cnt = 0;
    cin >> n;
    string even_string = "";
    for (int i = 0;i<n;i++)
    {
        int cnt;
        string b;
        cin >> cnt >> b;
        for (int i = 0;i<cnt;i++)
        {
            even_string = even_string  + b;
        }
    }
    if (is_wen(even_string) == true)
    {
        cout << 0;
        return 0;
    }
    else
    {
        int mid = even_string.size() / 2;
        int i = 0;
        int j = even_string.size() -1;
        while (i<mid && j>mid)
        {
            if (even_string[i] != even_string[j])
            {
                cnt++;
            }
            i++;
            j--;
        }

    }
    cout << cnt << endl;
    fclose(stdin);
    fclose(stdout);

}
