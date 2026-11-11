#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int a[N],p,cnt;
long long n,m,sum=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	cin >> n >> m;
	if(m==0){
		cout << 0;
	}
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		p=a[i+1]-a[i];
		if(p>m){
			continue;
		}
		if(p=m){
			if(cnt<2){
				cnt=2;
			}
		}
		for(int k=i+2;k<=n;k++){
		p+=(k-i)*(a[k]-a[k-1]);
		if(p>m){
			continue;
		}
		if(p=m){
			cnt=k-i+1;
			}
		}
	}
	cout << cnt;
	return 0;
}
