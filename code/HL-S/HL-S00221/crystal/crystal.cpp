#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m;
long long a[N];
long long pre[N];
bool cmp(long long a,long long b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	pre[1]=0;
	for(int i=2;i<=n;i++){
		pre[i]=pre[i-1]+(a[i]-a[i-1])*(i-1);
		if(pre[i]>m){
			cout<<i-1;
			return 0;
		}
	}cout<<n;
	return 0;
}
