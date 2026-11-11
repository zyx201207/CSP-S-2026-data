#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[300010],ff,c[300010],d=0;
struct node{
	bool f;
	int x;
}t[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!d) d=a[i];
		if(d!=a[i]&&c[d]==1) c[d]=2,d=a[i];
		if(c[a[i]]==0) c[a[i]]=1;
		if(c[a[i]]==2) ff=1;
	}
	if(!ff){
		int t=a[1];
		for(int i=1;i<=n+1;i++){
			if(a[i]!=t){
				ans[t]=i-1;
				t=a[i];
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<' ';
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		int b[500010]={0},len=0;
		for(int j=i;j<=n;j++){
			len++;
			if(t[a[j]].f){
				for(int k=1;k<=m;k++) if(t[k].x>t[a[j]].x) t[k].f=0;
				len=t[a[j]].x;
			}
			b[len]=a[j];
			t[a[j]].f=1;
			t[a[j]].x=len;
		}
		for(int j=1;j<=len;j++){
			ans[b[j]]++;
		}
		for(int j=1;j<=m;j++){
			t[j].f=0,t[j].x=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
