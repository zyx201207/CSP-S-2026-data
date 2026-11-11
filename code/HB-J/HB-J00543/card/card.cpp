#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int b[200005];
int c[100005];
int jishu;
queue<int>q;
int cnt[200005];
int flag = 1;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            for(int k=i;k<j;k++)
            {
                if(a[j] == a[k])
                {
                    while(!q.empty())
                    {
                        q.pop();
                    }
                }
            }
            q.push(a[j]);
        }
        while(!q.empty())
        {
			//cout << q.front();
            cnt[q.front()] ++;
            q.pop();
        }
        cout << endl;
    }
    for(int i=1;i<=m;i++)
    {
        cout << cnt[i] << ' ';
    }
    return 0;
}
