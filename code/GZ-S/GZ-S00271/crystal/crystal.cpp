//GZ-S00271 姓名：周昊杨 学校：贵阳市第一中学
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],ma,c,s,flag,x,flag1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]!=i)flag=1;
		if(i==2)x=a[2]-a[1];
		if(i>=3&&a[i]-a[i-1]!=x)flag1=1;
	}
	if(!flag){
		int s=m,cnt=0;
		int k=1;
		while(k<=s){
			s-=k;
			cnt++;
			k++;
		}
		cout<<cnt+1;
		return 0;
	}
	if(!flag1){
		int s=m,cnt=0;
		int k=x;
		while(k<=s){
			s-=k;
			cnt++;
			k+=x;
		}
		cout<<cnt+1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		s+=a[n]-a[i];
	}
	if(s<m){
		cout<<n;
		return 0; 
	}
	for(int i=2;i<=n;i++){
		
		int s=m,cnt=0;
		int h=i-1;
		if((a[i]-a[h])*ma>s)continue;
		if(h<=0)break;
		while(a[i]-a[h]<=s){
			s-=a[i]-a[h];
			cnt++;

			h--;
			if(h<=0)break;
		}
		ma=max(ma,cnt);
	}

	cout<<max(ma+1,1ll);
	return 0;
}
