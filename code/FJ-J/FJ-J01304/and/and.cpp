#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5;
int n,m;
int a[N+5];
int ans=0;
int flag1=0;
bool flag2=1;
bool flag3=0;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=20;j++){
			if(a[i]==pow(2,j)-1){
				flag1++;
				continue;
			}
		}
		if(a[i]>=4){
			flag2=0;
		}
		
	}
	//cout<<pow(2,5);
	for(int i=1;i<=20;i++){
		if(n==pow(2,i)){
			flag3=1;
			break;
		}
	}
	//cout<<flag1;
	if(n<=20){
		int all=1;
		for(int i=1;i<=n;i++){
			all*=2;
		}
//		int st=1;
//		for(int i=1;i<=m;i++){
//			st*=2;
//		}
		
		for(int i=1;i<all;i++){
			int cnt=0;
			int al;
			int tr=i;
			int fl=0;
			int now=1;
			while(tr>0){
				if(tr%2==1){
					if(fl==0){
						al=a[now];
						fl=1;
					}else{
						al&=a[now];
					}
					cnt++;
				}
				tr/=2;
				now++;
			}
		//	cout<<cnt;
			if(cnt!=m)continue;
			else ans=max(ans,al);
			
		}
		cout<<ans;
	}else if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}else if(m==n-1){
		sort(a+1,a+1+n,cmp);
		int ac=a[2];
		for(int i=2;i<=n-1;i++){
			ac&=a[i];
		}
		ans=max(ac&a[1],ac&a[n]);
		cout<<ans;
	}else if(flag1==n){
		sort(a+1,a+1+n,cmp);
		cout<<a[m];
	}else if(flag2){
		sort(a+1,a+1+n,cmp);
		ans=a[1];
		for(int i=2;i<=m;i++){
			ans&=a[i];
		}
		cout<<ans;
	}else if(flag3){
		sort(a+1,a+1+n,cmp);
		ans=a[1];
		for(int i=2;i<=m;i++){
			ans&=a[i];
		}
		cout<<ans;
	}else{
		cout<<0;
	}
	return 0;
}
