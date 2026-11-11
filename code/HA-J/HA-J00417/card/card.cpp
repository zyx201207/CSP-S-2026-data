#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,ne,fr;
}a[200010],c[200010];
int b[300010],d[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	c[0].ne=1;
	c[0].fr=0;
	for(int i=1;i<=n;i++){
		cin>>c[i].a;
		c[i].ne=i+1;
		c[i].fr=i-1;
	}
	c[n].ne=0;
	for(int q=1;q<=n;q++){
		memset(b+1,0,sizeof(b));
		for(int i=1;i<=n;i++){
			a[i].a=c[i].a;
			a[i].fr=c[i].fr;
			a[i].ne=c[i].ne;
		}
		for(int i=q;i<=n;i++){
			if(b[a[i].a]==0){
				b[a[i].a]=i;
			}
			else if(a[b[a[i].a]].a==a[i].a){
				for(int j=b[a[i].a];j<i;j++){
					b[a[j].a]=0;
					a[j].a=0;
				}
				a[a[b[a[i].a]].fr].ne=i;
				b[a[i].a]=i;
			}
//			for(int j=1;j<=m;j++){
//				cout<<b[j]<<' ';
//			}
//			cout<<endl;
		}
		for(int i=q;i<=n;i++){
			if(a[i].a!=0){
				d[a[i].a]++;
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<d[i]<<' ';
	return 0;
} 
