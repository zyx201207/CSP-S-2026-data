#include <bits/stdc++.h>
using namespace std;
int m,n,a[300005]={},b[500005],ans[300005];
struct node{
	int x=0,y;
};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int o=1;o<=n;o++){
		cin>>b[o];
	}
	for(int o=0;o<n;o++){
		int cc[500005];
		node book[300005];
		for(int i=1;i<=n-o;i++){
			cc[i]=b[i+o];
		}
		for(int i=1;i<=n-o;i++){
			if(book[cc[i]].x==0)
			{
				book[cc[i]].x=1;
				book[cc[i]].y=i;
			}
			else
			{
				for(int j=book[cc[i]].y+1;j<i;j++)
				book[cc[j]].x=0;
				book[cc[i]].y=i;
			}
		}
		for(int i=1;i<=m;i++)
		{
			if(book[i].x==1)
			ans[i]++;
		}
	}
	for(int i=1;i<=m;i++)
	cout<<ans[i]<<" ";
	return 0;
}
