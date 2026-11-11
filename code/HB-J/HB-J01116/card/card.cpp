#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n,m,r;
bool flag;
int a[N],b[N],t[N];
void put(int op){
	bool flag=0;
	int pid=0;
	for(int i=1;i<=r;i++){
		if(t[i]==a[op]){
			pid=i;
			flag=1;
			break;
		}
	}
	if(flag==1)r=pid,t[pid]=a[op];
	else r++,t[r]=a[op];
	return ;
}
int main()
{
	cin>>n>>m;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	for(int i=1;i<=n;i++)cin>>a[i];
	r=1;
	for(int k=1;k<=n;k++){
		for(int i=1;i<=k;i++){
			put(i);
		}
		for(int i=1;i<=r;i++){
			b[t[i]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<b[i]<<' ';
	return 0;
}
