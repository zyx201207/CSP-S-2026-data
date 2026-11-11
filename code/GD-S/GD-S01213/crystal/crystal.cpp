#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
#define cin FRead 
int n,m;
int a[500050];

struct fff{};

fff& operator>>(fff& ff,int& x){
	char ch=getchar();
	while(ch<=' ' || ch>'9')ch=getchar();
	int f=1;
	if(ch=='-'){
		f=-1;ch=getchar();
	}
	x=0;
	while(ch>='0' && ch<='9'){
		x=x*10;x=x+(ch-'0');
		ch=getchar();
	}
	x=x*f;
	return ff;
}

fff FRead;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	a[n+1]=a[n];
	int cur=0;
	int ans=0;
	for(int i=1,j=1;i<=n && j<=n;){
		while(j<=n && cur<=m){
			cur+=(j-i+1)*(a[j+1]-a[j]);
			j++;
		}
		cur-=(j-i)*(a[j]-a[j-1]);
		j--;
		ans=max(ans,j-i+1);
		cur-=a[j]-a[i];
		i++;
	}
	cout<<ans<<endl;
	return 0;
}
