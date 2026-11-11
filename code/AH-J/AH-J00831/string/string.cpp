#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n;
struct node{
	int start,end;
	char c;
}a[N];
int find(int k){
	int l=1,r=n;
	while(l<r){
		int mid=(l+r)/2;
		if(k>=a[mid].start && k<=a[mid].end)
			return mid;
		if(k<=a[mid].start)
			r=mid-1;
		else
			l=mid+1;
	}
}
int min(int a,int b){
	return a<b?a:b;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int len,k=1,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>len>>a[i].c;
		a[i].start=k;
		a[i].end=k+len-1;
		k=a[i].end+1;
	}
	k--;
	int l=1,r=k;
	while(l<r){
		int tmp1=find(l),tmp2=find(r);
		int tmp=min(a[tmp1].end-l+1,r-a[tmp2].start+1);
		if(a[tmp1].c!=a[tmp2].c)
			ans+=tmp;
		l+=tmp,r-=tmp;
	}
	cout<<ans<<endl;
	return 0;
}

