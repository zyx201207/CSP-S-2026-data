//GZ-S00325 贵阳市南明区华麟学校 陈锦江
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
long long pre[N],a[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	long long mx=-2;
	int l=1,r=1;
	while(l<=r&&r<=n){
		if((a[r]-a[l])*(r-l+1)+a[l]*(r-l+1)-(pre[r]-pre[l-1])<=m){
			r++;
		}else{
			if(r-l+1>mx){
				mx=r-l;
			}
			l++;
		}
	}
	cout<<mx;
	return 0;
}



