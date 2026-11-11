#include<bits/stdc++.h>
using namespace std;
int a[500005] = {0};
bool fold[500005] = {0};
int ans[300005] = {0};
int main()
{
   freopen("card.in", "r", stdin);
   freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++)
    {
        for(int x = 0; x < n; x++) fold[x] = false;
        for(int j = i; j < n; j++)
        {
            for(int k = i; k < j; k++)
            {
                if(a[k] == a[j] && fold[k] == 0)
                {
//                    cout <<"&&&&   " <<"i, j, k, = " <<i << " " << j <<" "<<k<<"\n";
                    for(int l = k; l < j; l++) fold[l] = 1;
                    break;
                }

            }
        }
        for(int j = i; j < n; j++) if(fold[j] == 0) ans[a[j]]++;
 /*       for(int l = i; l < n; l++)
        {
            cout <<"l=" << l <<"   fold[l] = " << fold[l] << "   a[l] = " <<a[l] <<"\n";
        }*/
    }
    for(int i = 1; i <= m; i++)
    {
        cout << ans[i] << " ";
    }
    fclose(stdin);    
fclose(stdout);
    return 0;
}
