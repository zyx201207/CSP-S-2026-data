#include <bits/stdc++.h>
using namespace std;
int a[1000002],box[1000002];
bool dis[1000002];
int n,m;
int maxx = 0;
void dfs(int x)
{
  if(x == m+1)
  {   for(int i = 1;i<=n;i++) maxx = max(maxx,box[i]);
  }
  for(int i = 1; i<= n;i++)
  {

            box[x] = a[i] & box[x];
            dis[i] = 1;
            dfs(x+1);
            dis[i] = 0;

  }
  return;

}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i<= n;i++)
    {
        cin >> a[i];
    }
    dfs(1);
    cout << maxx;
    fclose(stdin);
    fclose(stdout);
}
