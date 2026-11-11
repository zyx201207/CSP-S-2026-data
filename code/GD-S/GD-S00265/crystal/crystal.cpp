#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int maxn=5e5+10;
int n,m; 
int a[maxn];
int b[maxn];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	
	
	
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		b[i]=a[i+1]-a[i];
	}
	int ans=1;
	int now=0;
	int num=1;
	for(int l=1,r=1;l<=n,r<=n;){
		while(now+num*b[r]<=m&&r<n){
			now+=num*b[r];
			num++;
			r++;
			ans=max(ans,num);
		}//r++ 
		//if(ans==num) cout<<"now l,r,num:"<<l<<' '<<r<<' '<<ans<<'\n';
		now=now-(a[r]-a[l]); 
		l++;
		num--;
		if(l==n){
			break;
		}
	}
	cout<<ans;
	return 0;
}
/*
O(n^2)-->45pts
A-->15pts
B-->15pts
 
5 3
1 2 3 4 5
*/
 
