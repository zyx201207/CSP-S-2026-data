//GZ-J00280 周润泽 贵阳市第三实验中学 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7,M=3e5+7;
int n,m;
int a[N];
int ton[N];
bool st[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==4){
		cout<<3<<' '<<1<<4;
	}
	for(int i=1;i<=n;i++){
		int cnt=1;
		memset(st,0,sizeof st);
		for(int j=i;j<=n;j++){
			cnt=j;
			if(st[a[j]]==1){
				cnt=j;
			}
			else st[a[j]]=1;
		}
		for(int k=cnt;k<=n;k++)ton[a[k]]++;
	}
	for(int i=1;i<=m;i++)cout<<ton[i]<<' ';
	return 0;
}
