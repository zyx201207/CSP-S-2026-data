#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int id;
	string c;
}a[200055];
int b[200055];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].id>>a[i].c;
	}
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i].id;
		//cout<<b[i];
	}
	int ans=0;
	int l=1,r=b[n];
	int cntl=1,cntr=n;
	while(1){
		string x,y;
		if(l>b[cntl-1]&&l<=b[cntl]){
			x=a[cntl].c;
		}else{
			cntl++;
			continue;
		}
		if(r<=b[cntr]&&r>b[cntr-1]){
			y=a[cntr].c;
		}else {
			cntr--;
			continue;
		}
		//cout<<r-b[cntr-1];
		//cout<<x<<" "<<y<<" "<<cntl<<" "<<cntr<<'\n';
		if(x!=y){
			ans+=min(b[cntl]-l+1,r-b[cntr-1]);
		}
		int d=min(b[cntl]-l+1,r-b[cntr-1]);
		l+=d;
		r-=d;
		if(l>=r)break;
	}
	cout<<ans;
	return 0;
}
