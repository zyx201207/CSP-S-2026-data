#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[200005],lp,ld,rp,rd,sum,ans;
char c[200005];
string s = "_";
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i] >> c[i];
        sum += a[i];
        for(int j = 1;j <= a[i];j++)
            s += c[i];
    }
    cout << s << "\n";
    for(int i = 1,j = sum;i <= sum / 2;i++,j--)
        if(s[i] != s[j])
            ans++;
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    /*
    ll mid = (1 + sum) / 2 + (int)(sum & 1),ndl,ndr = 0,cnt = 0,midd,tmp;
    while(1)
    {
        cnt++;
        ndl = ndr + 1; ndr = ndl + a[i] - 1;
        if(ndr >= mid && ndl <= mid)
        {
            midd = cnt;
            tmp = mid - ndl + 1;
            break;
        }
    }
    lp = (tmp - 1 == 0) ? a[midd - 1] : tmp - 1; rp = (tmp + 1 > a[midd]) ? 1 : tmp + 1;
    ld = (tmp - 1 == 0) ? midd - 1 : midd;       rd = (tmp + 1 > a[midd]) ? midd + 1 : midd;
    while(l != 1 && r != n)
    {
        ll syl = lp - 1,syr = a[rd] - rp;
        int nql = nqr = midd;
        while(c[nql] == c[--nql] && nql > 0 && c[ld] == c[rd])
            syl += a[nql];
        while(c[nqr] == c[++nqr] && nqr <= sum && c[ld] == c[rd])
            syr += a[nqr];// count huiwen
        int snum = min(syl,syr),cl = snum - (lp - 1),cr = snum - (a[rd] - rp),cld = ld - 1,crd = rd + 1,dl,dr,pl = lp - 1,pr = rp + 1;

        while(c[cld] == c[--cld] && cld > 0 && snum && cl > 0)//calc where shipei begin
        {
            cl -= (a[cld] > cl) ? cl : a[cld];
            pl = cl;
            dl--;
        }
        while(c[crd] == c[++crd] && crd <= n && snum && cr <= n)
        {
            cr -= (a[crd] > cr) ? cr : a[crd];
            pr = cr;
            dr++;
        }

        //calc where shipei end and add ans
        int qlp = a[cld] - pl,qld = dl,qrp = a[crp] - pr,qrd = dr;
        while(qcl > 0 && )
        {

        }
        while(qcr <= sum && )
        {

        }
    }
    */

    return 0;
}
