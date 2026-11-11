#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
struct node{
	int num,fi,li;
}a[N];
int b[N],c[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("crad.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].num;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			c[j]=a[j].num;
			a[j].fi=0;
		}
		sort(c+1,c+n+1);
		bool flag=1;
		for(int j=i;j<=n;j++){
			if(c[j]==c[j-1])flag=0;
		}
		if(flag==1){
			for(int j=i;j<=n;j++){
				b[j]++;
			}
		}
		else{
			int now;
			for(int j=i;j<=n;j++){
				if(a[a[j].num].fi==0)a[a[j].num].fi=j;
				else{
					a[a[j].num].fi=j;
					now=a[a[j].num].fi;
				}
			}
			for(int j=now;j<=n;j++){
				b[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
