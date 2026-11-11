#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int n,m,a[200010]={0},w,a1[200010]={0},maxn=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		w=30;
		while(a[i]>0){
			if(a[i]>pow(2,w)) 
			{
				a1[i]+=pow(10,w);
				a[i]-=pow(2,w);
			}
			w--;
		}
		a1[i]+=1;
		if(a1[i]%10==2) a1[i]+=8;
		cout<<a1[i];
	}
	for(int j=1;j<=3;j++)
	{
		maxn=max(maxn,a1[j]);
	}
	cout<<maxn;
	return 0;
}

