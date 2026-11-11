#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],s[500010],p[500010],ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int t=1;t<=n;t++){
		memset(s,0,sizeof(s));
		memset(s,0,sizeof(s));
		int len=0;
		for(int i=t;i<=n;i++){
			if(s[a[i]]!=0){
				int t=s[a[i]]-1;
				for(int j=s[a[i]];j<=len;j++){
					s[p[j]]=0;
					p[j]=0;
				}
				len=t;
			}
			len++;
			s[a[i]]=len;
			p[len]=a[i];
		}
		for(int i=1;i<=len;i++){
			ans[p[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
