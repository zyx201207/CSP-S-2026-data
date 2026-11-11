#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+5;
long long k;
int m,n;
struct Node{
	long long v;
	long long d;
}a[N];
bool cmp(Node x,Node y){
	return x.v>y.v;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].v;
		for(int j=30;j>=0;j--){
			if(a[i].v>(long long)(pow(2,j))){
				a[i].d=j+1;
				break;
			}
		}
	}
	sort(a+1,a+1+n,cmp);
	
	long long n=a[m].d;
	for(int i=m;i>=1;i--){
		a[i].v-=((a[i].v>>n)<<n);
	}
	sort(a+1,a+n+1,cmp);
	long long ans=a[1].v;
	for(int i=2;i<=m;i++){
		ans&=a[i].v;
	}
	cout<<ans;
	return 0;
}
