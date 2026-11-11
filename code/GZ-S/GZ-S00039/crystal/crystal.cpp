//GZ-S00039 贵阳市第一中学 吴昊然
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m,a[N],d[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long sum=0,w=1,len=1,mx=1;
	for(int i=2;i<=n;i++){
		sum+=1LL*(a[i]-a[i-1])*len;
		len++;
		while(sum>m){
			sum-=a[i]-a[w];
			len--;
		}
		mx=max(len,mx);
	}
	cout<<mx;
	return 0;
} 
