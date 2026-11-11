#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll n;
struct node
{
    ll len;
    char ch;
}s[200010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {

        cin >> s[i].len >> s[i].ch;
    }
    ll l = 1,r = n,num = 0,op = 0,ans = 0;
    while(l < r){
        if(op == 0 && num == 0){
            if(s[l].ch == s[r].ch){
                if(s[l].len > s[r].len){
                    num = s[l].len - s[r].len;
                    op = 1;
                    r--;
                }
                else if(s[r].len > s[l].len){
                    num = s[r].len - s[l].len;
                    op = 2;
                    l++;
                }
                else
                {
                    l++,r--;
                }
            }
            else{
                if(s[l].len > s[r].len){
                    num = s[l].len - s[r].len;
                    ans += s[r].len;
                    op = 1;
                    r--;
                }
                else if(s[r].len > s[l].len){
                    num = s[r].len - s[l].len;
                    op = 2;
                    ans += s[l].len;
                    l++;
                }
                else
                {
                    ans += s[l].len;
                    l++;
                    r--;

                }
            }
        }
        else if(op == 1){
            if(s[l].ch == s[r].ch)
            {
                if(num > s[r].len)
                {
                    num -= s[r].len;
                    r--;
                }
                else if(s[r].len > num)
                {
                    num = s[r].len - num;
                    op = 2;
                    l++;
                }
                else
                {
                    l++;
                    r--;
                    num = 0;
                    op = 0;
                }
            }
            else
            {
                if(num > s[r].len)
                {
                    num = num - s[r].len;
                    ans += s[r].len;
                    r--;
                }
                else if(s[r].len > num)
                {
                    ans += num;
                    num = s[r].len - num;
                    op = 2;
                    l++;
                }
                else
                {
                    ans += s[r].len;
                    l++;
                    r--;
                    num = 0;
                    op = 0;
                }
            }
        }
        else if(op == 2)
        {
            if(s[l].ch == s[r].ch)
            {
                if(num > s[l].len)
                {
                    num -= s[l].len;
                    l++;
                }
                else if(s[l].len > num)
                {
                    num = s[l].len - num;
                    op = 1;
                    r--;
                }
                else
                {
                    l++;
                    r--;
                    num = 0;
                    op = 0;
                }
            }
            else
            {
                if(num > s[l].len)
                {
                    num = num - s[l].len;
                    ans += s[l].len;
                    l++;
                }
                else if(s[l].len > num)
                {
                    ans += num;
                    num = s[l].len - num;
                    op = 1;
                    r--;
                }
                else
                {
                    ans += s[l].len;
                    l++;
                    r--;
                    num = 0;
                    op = 0;
                }
            }
        }
    }
    cout << ans;

}
