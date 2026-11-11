#include<bits/stdc++.h>
using namespace std;
int a[500005];
bool b[300005];
long long sum[300005];
int main()
{
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
int n,m;
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
for(int i=1;i<=n;i++){
	memset(b,0,sizeof(b));
	int f=i;
	for(int j=i;j<=n;j++){
		if(b[a[j]]>=f){
			f=j;
		}
		b[a[j]]=j;
	}
	for(int j=1;j<=n;j++){
		if(!b[a[j]])sum[a[j]]++;
		b[a[j]]=1; 
	} 
}
for(int i=1;i<=m;i++){
	cout<<sum[i]<<" ";
}
return 0;
}
