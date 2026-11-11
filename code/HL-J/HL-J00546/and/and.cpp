#include<bits/stdc++.h>
using namespace std;
long long x[200005],maxnn=0,y[200006],maxn=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	if(m==1)
	{
	for(int i=1;i<=n;i++){
		if(x[i]>maxn)
		maxn=x[i];
	}	
	cout<<maxn;
	}
	if(m==2)
	{
	for(int j=1;j<=n;j++){
	for(int i=1;i<=n;i++){
		if(x[j]==x[i])
		y[j]==x[j];
	}
	}
	for(int i=1;i<=n;i++){
		if(y[i]>maxnn)
		maxnn=y[i];
}
cout<<maxnn;
}
	return 0;
}