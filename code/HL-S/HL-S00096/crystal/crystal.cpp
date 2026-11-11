#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1;
int n,ans;
long long m;
struct x{
	long long v;
	int o;
}a[N];
bool cmp(x p,x q){
	if(p.v==q.v){
		return p.o<q.o;
	}return p.v<q.v;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	//cout<<1<<" ";
	for(int i=1;i<=n;i++){
		cin>>a[i].v;
		//cout<<2<<" ";
	}sort(a+1,a+n+1,cmp);
	for(int i=2;i<=n;i++){
		//cout<<a[i].v<<" ";
		//cout<<3<<" ";
		long long s=a[i].v;
		int f=0,w=m;
		for(int j=i-1;j>=1;j--){
			if(a[j].v==s){
				f++;
				continue;
			}if(s-a[j].v>w){
				break;
			}else{
				w-=(s-a[j].v);
				f++;
			}
		}ans=max(ans,f);
	}cout<<ans+1;
	return 0;
}
