#include<bits/stdc++.h>
using namespace std;

int n , k;
char p;
struct node{
    int r;
    char c;
};
node s[20000002];
int cnt = 0 , len = 0 , ans = 0 , mem = 0;

int main()
{
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);

    cin >> n;
    while(n--)
    {
        cin >> k;
        cin >> p;
        if(p == s[cnt].c)
            s[cnt].r += k;
        else{
            cnt++;
            s[cnt].c = p;
            s[cnt].r = k;
        }
        len += k;
    }
    int halflen = len / 2 + len % 2;
    mem = cnt;
    cnt = 1;
    int x , y = 0;
    while(y == halflen){
        if(s[cnt].c == s[mem].c)
        {
            x = min(s[cnt].r , s[mem].r);
            s[cnt].r -= x;
            s[mem].r -= x;
        }
        else
        {
            x = min(s[cnt].r , s[mem].r);
            s[cnt].r -= x;
            s[mem].r -= x;
            ans += x;
        }
        if(s[cnt].r == 0)
            cnt ++;
        if(s[mem].r == 0)
            mem --;
        y+=x;
    }
    cout << ans;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
