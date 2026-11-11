#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N=5e5+5;

int n,m;
int l,r;
bool flag=1;
int ans[N];
int a[N];
bool f[N];
int st[N],top=0;


int main(){
	freopen ("card.in","r",stdin);
	freopen("card.ans","w",stdout);
	//freopen("card3.in","r",stdin);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
		
	for(int i=2;i<=n;i++)
		if(a[i]<a[i-1])
			flag=0;
			
	if(flag){
		for(int i=1;i<=n;i++){
			while(a[i]==a[i+1])
				i++;
			cout<<i<<' ';
		}
		return 0;
	}
	

	for(int i=1;i<=n;i++){
		top=0;
		fill(f,f+N,0);
		for(int j=i;j<=n;j++){
			if(!f[a[j]]){
				f[a[j]]=1;
				st[++top]=a[j];
			}
			else {
				while(top>0&&st[top]!=a[j]){
					f[st[top]]=0;
					top--;
				}
				f[a[j]]=1;
			}	
		}
		while(top){
			ans[st[top]]++;
			top--;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	
	return 0;
} 
