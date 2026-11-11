#include<string>
#include<iostream>
int n;
using namespace std;
int main()
{
    int a = 0;
    string s;
    cin >> n;
    for(int i = 0 ; i < n; i++)
    {
        cin >> a;
        for(int j = 0; j < a; j++)
        {
            cin >> s;
        }
    }
    int l = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] != s[s.length-i])
        {
            s[i] = s[s.length-i];
            l++;
        }
    }
    cout << l;
    return 0;
}
