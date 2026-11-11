#include<bits/stdc++.h>
//#define int long long
using namespace std;
using ll = long long;
vector<string> v;
ll cnt[500000];
ll n,m;
string to2(ll n)
{
    string str;
    string str1;
    while(n > 0)
    {
        if(n % 2 == 1) str += "1";
        else str += "0";
        n /= 2;
    }
    //for(int i=0;i<32-str.length();i++) str += "0";
    for(ll i=str.length()-1;i>=0;i--)
    {
        str1 += str[i];
        if(str[i] == '1') cnt[i] ++;
    }
    return str1;
}
ll to10(string s1)
{
    ll base = 1;
    ll ans = 0;
    for(ll i=s1.length()-1;i>=0;i--)
    {
        if(s1[i] == '1') ans += base;
        base *= (1LL * 2);
    }
    return ans;
}
bool cmp(string s1,string s2)
{
    ll len = max(s1.length(),s2.length());
    for(ll i=len-1;i>=0;i--)
    {
        if(cnt[i] >= m) // right base
        {
            if((ll)s2.length() < i+1) return true;
            else if((ll)s1.length() < i+1) return false;
            else if(s2[i] == '0' && s1[i] == '1') return true;
            else if(s1[i] == '1' && s2[i] == '0') return false;
        }
        else continue;
    }
    return true;
}
string ad(string s1,string s2)
{
    string ans;
    if(s1.length()<s2.length()) swap(s1,s2);
    ll dl = s1.length() - s2.length();
    for(ll i=0;i<dl;i++) ans += "0";
    ans += s2;
    for(ll i=0;i<s1.length();i++)
    {
        if(ans[i] == '1' && s1[i] == '1') ans[i] = '1';
        else ans[i] = '0';
    }
    return ans;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    //cout << ad("101100","10110");
    //return 0;
    cin >> n >> m;
    for(ll i=0;i<n;i++)
    {
        ll val;
        cin >> val;
        v.push_back(to2(val));
    }
    //for(auto i : v) cout << i << " ";
    //for(int i=0;i<=4;i++)
    //{
    //    cout << i << " " << cnt[i] << endl;
    //}
    //cout << endl;
    sort(v.begin(),v.end(),cmp);
    //cout << "2 right" << endl;
    //for(auto i : v) cout << i << endl;
    string ans = v[0];
    for(ll i=1;i<m;i++) ans = ad(ans,v[i]);
    cout << to10(ans);
    return 0;
}
