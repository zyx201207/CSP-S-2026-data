#include <bits/stdc++.h>
using namespace std;
long long int a1[100055];//jishu
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >>n;
    string s;
    for (int i = 0;i<n;i++)
    {
        int a;
        cin >>a;
        char s12;
        cin >>s12;
        int ans = (int)s12-'0';
        a1[ans]++;
        for (int j = 0;j<a;j++)
        {
            s += s12;
        }
    }
    string pan;
    pan += s;
    reverse(pan.begin(),pan.end());
    if (s==pan)
    {
        cout <<0;
        return 0;
    }
    int l = 0,r = s.size();
    int ans=0;
    while(l<r)
    {
        //cout <<s[l]<<" "<<s[r-1]<<" ";
        if (s[l] == s[r-1])
        {
            l++;
            r--;
            continue;
        }
        else
        {
            int pz1 = s[l]-'0';//zuo
            int pz2 = s[r-1]-'0';//you
            if(a1[pz1]>=a1[pz2])
            {
                s[r-1] = s[l];
                a1[pz1]++;
                l++;
                r--;
            }
            else
            {
                a1[pz2]++;
                s[l] = s[r-1];
                l++;
                r--;
            }
            ans++;
        }
    }
    cout <<ans;
    return 0;
}
// aabababa
