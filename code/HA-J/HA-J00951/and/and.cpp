#include<bits/stdc++.h>
using namespace std;
long long n,m,ma=-1e9,cnt,a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n,greater<int>());
	if(m==1)cout<<a[0];
	else if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				ma=max(ma,a[i]&a[j]);
			}
		}
		cout<<ma;
	}else{
		ma=a[0];
		for(int i=1;i<m;i++)ma&=a[i];
		cout<<ma;
	}
	return 0;
}
