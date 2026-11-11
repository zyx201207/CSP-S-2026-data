#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n=0;
ll a[200010]={},cnt=0;
char c[200010]={};
int j;
int leftt=0,rightt=0;
char lefx,rigx;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	if(n==1) {
		cout<<0;
		return 0;
	}
	int i=1;j=n;
	leftt=a[i];rightt=a[j];
	lefx=c[i];rigx=c[j];
	while(i< j)
	{
		if(leftt>rightt){
			if(lefx!=rigx) cnt+=rightt;
			leftt-=rightt;
			if(i<j-1){
				rightt=a[--j];
				rigx=c[j];
			} 
			else break;
		}
		if(leftt==rightt){
			if(lefx!=rigx) cnt+=rightt;
			leftt=0;
			rightt=0;
			if(i<j-2){
				rightt=a[--j];
				rigx=c[j];
				leftt=a[++i];
				lefx=c[i];
			}
			else break;
		}
		if(leftt<rightt){
			if(lefx!=rigx) cnt+=leftt;
			rightt-=leftt;
			if(i<j-1){
				leftt=a[++i];
				lefx=c[i];
			}
			else break;
		}
	}
	cout<<cnt;
	return 0;
 } 
