#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct num{
	int a,key;
	bool operator<(num b){
		return key>b.key;
	}
}a[N];
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].a;
	}
	for(int i=30;i>=0;i--){
		for(int j=1;j<=n;j++){
			a[j].key=((a[j].a>>i)&1);
		}
		sort(a+1,a+n+1);
		int pos=0;
		for(int j=1;j<=n;j++){
			if(a[j].key==0){
				pos=j-1;
				break;
			}
		}
		if(pos>=m){
			n=pos;
		}
	}
	int ans=a[1].a;
	for(int i=1;i<=m;i++)ans=(ans&a[i].a);
	cout<<ans;
	return 0;
}

