#include<bits/stdc++.h>
using namespace std;
const int N=500001,M=300001;
int n,m,a[N],cnt[M],p,s[N],ans[M],head;
int main(){//4 3 1 2 1 3
	freopen("card.in","r",stdin);
	freopen("card.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];//1 2 1 3
		if(cnt[a[i]])p=cnt[a[i]];//p=1
		cnt[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
	    memset(cnt,0,sizeof(cnt));
	    memset(s,0,sizeof(s));
		head=0;
		if(i>p)for(int j=i;j<=n;j++)ans[a[j]]++;
		else{
			for(int j=i;j<=n;j++){
				int k=a[j];//10 3 
				s[++head]=k;//3 1 2 1 3 2 3 1 2 1
				if(cnt[k])head=cnt[k];
				cnt[k]=head;
			}
			for(int j=1;j<=head;j++)ans[s[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
