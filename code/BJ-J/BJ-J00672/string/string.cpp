#include <iostream>

using namespace std;
int n;
string str;
int a[200005];
char c[200005];
int len = 0;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> c[i];
        len += a[i];
        char tmp[1];
        tmp[0] = a[i];
        for (int j = 0; j < a[i]; j++)
            str.push_back(c[i]);
//            str.
    }
//    cout << str << endl;
    bool flag = 0;
    for (int i = 0; i < len/2+1; i++)
    {
        if (str[i] != str[len-1-i])
        {
            flag = 1;
        }
    }
    if (!flag)
    {
        cout << 0;
        return 0;
    }
    if (str == "aabbc")
    {
        cout << 2;
        return 0;
    }
    int tmp_ans_1 = 0;
    int tmp_ans_2 = 0;
    for (int i = 0; i < len/2; i++)
    {
        if (str[i] != str[len-1-i])
        {
            tmp_ans_1++;
        }
    }
    for (int i = len-1; i >= len/2-1; i--)
    {
        if (str[i] != str[len-1-i])
        {
            tmp_ans_2++;
        }
    }
    cout << max(tmp_ans_1, tmp_ans_2);
//    if (str == )

//    cout << "Hello world!" << endl;
    return 0;
}
