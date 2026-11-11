#include<bits/stdc++.h>
using namespace std;
int a[5000+5],cnt[5000+5],yx[5005];
int erfen(int x,int y,int j)
{
	for(;x<=y;x++){
		if(yx[x]==j){
			return x;
		}
	}
	return -1;
}
void cd(int &head,int j)
{
	while(head!=j){
		head++;
	}
	
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,gs=0,head=1;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		head=1;gs=0;
		for(int j=i-1;j<=n;j++){
			int x=erfen(i-1,j,a[j]);
			if(x==-1){
				gs++;
				yx[gs]=a[j];
			}else{
				cd(head,j);
				gs++;
				yx[gs]=a[j];
			}
		}
		for(int j=head;j<=n;j++){
			cnt[yx[j]]++;
		}
		for(int j=i-1;j<=n;j++){
			yx[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
} 
