#include<bits/stdc++.h>
#define ll long long
#define N 10010
using namespace std;
int n,m,a[N],ans[N];
struct node{
	int x,y;
	int q[N];
}b[N];//bÊÇÍ°Êý×é 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++) ans[i]=n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int i=1;i<=m;i++){
			b[i].x=b[i].y=0;
		} 
		for(int j=i;j<=n;j++){
			b[a[j]].x++;
			b[a[j]].q[b[a[j]].x]=j;
		}
		for(int j=i+1;j<=n;j++){
			if(b[a[j]].x){
				for(int t=b[a[j]].q[b[a[j]].y+1];t<j;t++){
					b[a[t]].x--;
					b[a[i]].y++;
				}
			}
		}
		for(int i=1;i<=m;i++){
			//cout<<b[i]<<' ';
			if(b[i].x>0) ans[i]++;
		}
		//cout<<endl;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
