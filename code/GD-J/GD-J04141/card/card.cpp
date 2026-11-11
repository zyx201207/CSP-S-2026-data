#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[300010]={0},c[500010];
void card(int x,int cnt){
	if(x>n){
		for(int i=1;i<=cnt;i++){
			b[c[i]]++;
//			for(int j=1;j<=cnt;j++)cout<<c[i]<<" ";
//			cout<<cnt<<'\n';
		}
		return;
	}for(int i=1;i<=cnt;i++){
		if(c[i]==c[cnt]){
			for(int j=i+1;j<=cnt;j++){
				c[j]=0;
				cnt-1;
			}break;
		}
	}c[cnt+1]=a[x+1];
	card(x+1,cnt+1);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(c,sizeof(c),0);
		c[1]=a[i];
		card(i,1);
	}for(int i=1;i<=m;i++)cout<<b[i]<<" ";
	return 0;
} 
