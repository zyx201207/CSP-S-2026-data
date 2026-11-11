#include<bits/stdc++.h>
using namespace std;
int ans[300005]={},n,m,a[500005],b[300005]={},c[500005]={};
void check(int x)
{
	int s[m+1]={};
	for(int i=x;i<=n;){
		s[a[i]]=max(s[a[i]],1);
		if(c[i]>i){
			i=c[i];
		}
		else{
			i+=1;
		}
	}
	for(int i=1;i<=m;i++){
		ans[i]+=s[i];
	}
	return;
}
int main()
{ 
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[b[a[i]]]=i;
		b[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		check(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
