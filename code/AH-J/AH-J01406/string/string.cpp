#include<Bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
struct node{
	int x;
	char c;
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	int n,len=0,mid=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
		len+=a[i].x;
	}
	for(int i=1,sum=0;i<=n;i++){
		if(sum+a[i].x>=(len+1)/2){
			mid=i;
			break;
		}
		sum+=a[i].x;
	}
	for(int i=1,j=n;i<=mid&&j>=mid;){
		if(a[i].x<a[j].x){
			if(a[i].c!=a[j].c) ans+=a[i].x;
			a[j].x-=a[i++].x;
		}
		else if(a[i].x>a[j].x){
			if(a[i].c!=a[j].c) ans+=a[j].x;
			a[i].x-=a[j--].x;
		}
		else{
			if(a[i].c!=a[j].c) ans+=a[i].x;
			i++,j--;
		}
	}
	cout<<ans;
	return 0;
}
