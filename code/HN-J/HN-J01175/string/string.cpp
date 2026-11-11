#include<bits/stdc++.h>
using namespace std;
long long n,ans;
struct snode{
	long long x;
	char c;
}a[200005];
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i].x>>a[i].c;
	}
	long long i=1,k=n;
	while(i<=k){
		if(a[i].c!=a[k].c){
			ans+=min(a[i].x,a[k].x);
			a[i].x-=a[k].x;
			a[k].x-=a[i].x;
			if(a[k].x<=0){
				k--;
			}
			if(a[i].x<=0){
				i++;
			}
		}else{
			a[i].x-=a[k].x;
			a[k].x-=a[i].x;
			if(a[k].x<=0){
				k--;
			}
			if(a[i].x<=0){
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}
