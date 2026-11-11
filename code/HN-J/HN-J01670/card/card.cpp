#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=3e5+1;

int n,m,a[N],ans[N],stk[N],top=0;
bool b[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int j=1;j<=n;j++){
		top=0,memset(b,false,sizeof(b));
		for(int i=j;i<=n;i++){
			if(b[a[i]])
				while(top&&stk[top]!=a[i])
					b[stk[top]]=false,top--;
			else
				stk[++top]=a[i],b[a[i]]=true;
		}
		for(int j=1;j<=top;j++)
			ans[stk[j]]++;
	}
	for(int i=1;i<=m;i++) 
		cout<<ans[i]<<' ';
}
