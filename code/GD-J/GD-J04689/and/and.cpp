#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,a[N],p[21],now,ans=-1;
bool cmp(long long x,long long y){
	return (x&p[now])>(y&p[now]);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
		for(int j=20;j>=0;j--){
			if(a[i]&(1<<j)){
				p[j]=max(p[j],a[i]);
			}
		}
	}
	for(now=20;now>=0;now--){
		sort(a,a+n,cmp);
		for(int i=1;i<m&&p[now]>ans;i++){
			p[now]&=a[i];
		}
		ans=max(ans,p[now]);
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
}
