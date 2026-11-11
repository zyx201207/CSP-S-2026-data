#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long maxx=-1;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
	   for(int i=1;i<=n;i++)if(a[i]>maxx)maxx=a[i];
	   cout<<maxx;return 0;
	}
	if(m==2){
	   for(int i=1;i<=n;i++)
	   for(int j=i+1;j<=n;j++)if((a[i]&a[j])>maxx)maxx=a[i]&a[j];
	   cout<<maxx;return 0;
	}
		sort(a+1,a+n+1,cmp);
		long long kk=a[1]&a[2];
		for(int i=3;m>2;i++,m--)kk=kk&a[i];
		cout<<kk;
	return 0;
}
