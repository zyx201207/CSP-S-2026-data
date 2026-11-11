#include<bits/stdc++.h>
using namespace std;
string s;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n , b;
    cin >> n;
    string a;
    while(n --)
    {
        cin >> b >> a;
        for(int i = 0; i <= b; i ++)
        {
        	s[i] = a;
		}
    }
    int len = s.size();
    int sum = 0 , len1 = len - 1;
    for(int i = 0; i <= len - 1; i ++)
    {
        if(s[i] == s[len1])
        {
            len1 --;
        }
        else
        {
            s[len1] = s[i];
            sum ++;
        }
    }
    cout << sum;
    return 0;
}
