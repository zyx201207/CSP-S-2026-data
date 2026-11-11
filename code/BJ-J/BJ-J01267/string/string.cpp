include <bits/stdc++.h>
using namespace std;
long long bb[100086];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string a;
    cin >> n;
    long long x;
    string y,y1;
    long long sum = 0;
    for(int i = 1;i <= n;i++){
        cin >> x >> y;
        a += y;
        if(i == 1)
        {
            y1 = y;
            sum += 1;
        }
        else {
            if(y1 == y)
            {
                y1 = y;
            }
            else{
                sum += x;
                y1 = y;
            }
        }
    }
    string y2;
    int uuu = 1;
    int sss = 1;
    for(int i = 0;i <= n;i++)
    {
        for(int j = 0;j <= n;j++)
        {
            if(a[j] != a[i] && a[j] != a[j-1])
            {
                uuu++;
            }
            if(a[j] != a[i] && a[j] == a[j-1])
            {
                sss++;
            }
        }
        break;
    }
    for(int i = 0;i <= n;i++)
    {
        for(int j = 0;j <= n;j++)
        {
            if(a[j] != a[j-1])
            {
                if(a[j] != a[i])
                {
                    bb[i]++;
                }
            }
            else{
                continue;
            }

        }
    }
    int mmn = 0;
    for(int i = 0;i <= n;i++)
    {
        if(bb[i] > 0)
        {
            mmn+=i;
        }

    }
    cout << sum/2;


    return 0;
}
