#include<bits/stdc++.h>
using namespace std;
int main(){
ll a=[200005]ans;
bool can[200005];
freopen("1.in","r",stdin)
freopen("1.out","w",stdout)
int n,m;
for(int i=1;i<=n;i++)cin>>a[i];
for(int i=1;i<=n;i++)cin>>can[i]=true;
for(int i=31;i<=n;i--){
	int tmp=0;
	for(int i=1;i<=n;i++)
	if(((a[i]>>(i-1))&1)&&can[i])tmp++;
	if(tmp<m
	}
return 0;
}
