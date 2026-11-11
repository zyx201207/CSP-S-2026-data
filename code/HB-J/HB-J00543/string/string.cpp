#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt;
char s;
struct node
{
    long long cnt,num;
    char s;
    int flag;
}a[200005];
char sd[30];
long long jishu;
bool cmp(node x,node y)
{
    return x.cnt > y.cnt;
}
long long sum;
long long sdf,sfg;
int theflag;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i].num >> a[i].s;
        theflag = 0;
        for(int j=0;j<jishu;j++)
        {
            if(a[i].s == sd[j])
            {
				theflag = 1;
                break;
            }
        }
        sd[jishu] = a[i].s;
        jishu ++;
        if(!theflag) sum ++;
        a[a[i].s - 'a' + 1].cnt += a[i].num;
    }
    //cout << sum << endl;
    sort(a+1,a+n+1,cmp);
    if(sum == 3 || sum == 2)
    {
        cout << a[2].cnt << endl;
        return 0;
    }
    if(sum == 1)
    {
        cout << 0 << endl;
        return 0;
    }
    else
    {
        for(int i=2;i<=26;i++)
        {
            if(sdf <= sfg)
            {
                sdf += a[i].cnt;
            }
            else
            {
                sfg += a[i].cnt;
            }
        }
    }
    cout << max(sdf,sfg) << endl;
    return 0;
}
