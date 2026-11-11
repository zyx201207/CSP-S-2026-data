#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],b[500005],ans[500005],res[500005];
int n,m;
int read(){
	int t=1;
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')t=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return t*x;
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++){
		a[i]=read();
		res[a[i]]++;
	}
	int cnt=0,tmp=0;
	while(cnt!=(n+1)){
		res[a[cnt]]--;
		cnt++;
		for(int i=cnt;i<=n;i++){
			b[++tmp]=a[i];
			if(res[a[i]]>1){
				for(int j=i+1;j<=n;j++){
					if(a[j]==a[i]){
						i=j;
					}
				}
			}
		}
		for(int i=1;i<=tmp;i++){
			ans[b[i]]++;
		}
		tmp=0;
		
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
    return 0;
}
