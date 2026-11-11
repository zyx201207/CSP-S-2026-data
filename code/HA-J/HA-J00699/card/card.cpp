#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int ans[300010];
int l;
int t[300010];
int st[300010],top=0;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		top=0;
		memset(t,0,sizeof(t));
		for(int j=i;j<=n;j++){
			if(t[a[j]]>0){
				while(top>0&&st[top]!=a[j]){
					t[st[top]]--;
					top--;
				}
				t[st[top]]--;
				top--;
			}
			t[a[j]]++;
			st[++top]=a[j];
		}
		for(int j=1;j<=top;j++) ans[st[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
