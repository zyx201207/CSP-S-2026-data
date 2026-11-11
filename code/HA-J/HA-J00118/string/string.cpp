#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2*1e5+7;
int n,f=1;
ll sum,ans,nw;
struct node{
	int t;
	char s;
}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i].t>>a[i].s;
		nw+=a[i].t;
		if(i>1&&a[i].s!=a[i-1].s&&f==1) f=0;
	}
	if(f==1||n==1){
		cout<<0;
		return 0;
	}
	int i=1,j=n;
	nw=(nw+1)/2;
	while(i<j&&nw>=0){
		int x=a[i].t,y=a[j].t;
		char s1=a[i].s,s2=a[j].s;
		if(x<y) nw-=a[i].t;
		if(x>y) nw-=a[j].t;
		if(x==y) nw=nw-a[i].t-a[j].t;
		if(s1!=s2){
			if((a[i+1].s==s2&&nw>=0)||(a[j-1].s==s1&&nw>=0)) ans+=abs(x-y);
			ans+=min(x,y);
		}
		if(x<y) i++;
		if(x>y) j--;
		if(x==y) i++,j--;
	}
	cout<<ans;
	return 0;
}
