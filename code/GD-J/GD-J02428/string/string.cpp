#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,x,ans;
long long k=1;
char c;
struct xx{
	//s:开始, t：结束, c:期间字符 
	int s,t;
	char c;
}a[200010];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		a[i]={k,k+x-1,c};
		k+=x;
	}
	//遍历一半 
	for(int i=1;i<=k/2;i++){
		int p=k-i;//对应字符 
		//二分查找最后一个左边界小于s[i]对应字符所在区间
		int l=1,r=n;
		while(l<=r){
			int mid=(r-l)/2+l;
			if(a[mid].s>p) r=mid-1;
			else l=mid+1;
		} 
		int cnt=r;
		//cout<<r<<' '; //查找到区间编号 
		l=1,r=n;
		//二分查找i所在区间编号 
		while(l<=r){
			int mid=(r-l)/2+l;
			if(a[mid].s>i) r=mid-1;
			else l=mid+1;
		} 
		int now=r;
		//cout<<r; //查找到区间编号 
		if(a[cnt].c!=a[now].c) ans++;//如果不同，需更改一次 
	}
	cout<<ans;
	
	//for(int i=1;i<=n;i++) cout<<a[i].s<<' '<<a[i].t<<' '<<a[i].c;
	
	
}
