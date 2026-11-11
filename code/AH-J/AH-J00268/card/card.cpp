#include<bits/stdc++.h>
using namespace std;

const int N=500005,M=300005;

int n,m,a[N],dui[M];
int bl[M],ans[M];

int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')	c=getchar();
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		a[i]=read();
		dui[a[i]]=i;
		bl[a[i]]++;
	}
	for(int i=n;i>=1;i--){
		if(i==dui[a[i]]){
			for(int j=i;j<=n;j++){
				j=dui[a[j]];
				ans[a[j]]+=bl[a[i]];
			}
		}
	}
	for(int i=1;i<=m;i++)	printf("%d ",ans[i]);
	puts("");
}
