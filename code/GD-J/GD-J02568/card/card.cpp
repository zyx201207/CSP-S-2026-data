#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

//ջ 
int n,m;
int a[N],b[N];
int st[N],top;
int cnt[N];
int ans[N];

void solve(int u)
{
	memset(cnt,0,sizeof(cnt));
	memset(st,0,sizeof(st));
	int k = n - u + 1;
	for (int i = 1;i <= k;i++) b[i] = a[i + u - 1];
	top = 0;
	for (int i = 1;i <= k;i++)
	{
		int pos = cnt[b[i]];
		if (pos){
			while (top > pos){
				cnt[b[st[top]]] = 0;
				st[top] = 0;
				top--;
			}
		}
		else st[++top] = i,cnt[b[i]] = top;
	}
	for (int i = 1;i <= top;i++) ans[b[st[i]]]++;
}

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i <= n;i++) cin>>a[i];
	for (int i = 1;i <= n;i++) solve(i);
	for (int i = 1;i <= m;i++) cout<<ans[i]<<" ";
	cout<<"\n";
	return 0;
}
