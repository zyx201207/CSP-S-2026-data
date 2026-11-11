#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005];
long long m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int js=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int k=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]==k){
			js++;
		}
	}
	sort(a+1,a+n+1);
	if(n>5000&&js==n-1){
		int zs=a[2]-a[1];
		int cnt=1;
		while(1){
			if(m>=zs*2){
				bool js=0;
				if(n/2-zs/(a[2]-a[1])>=1){
					m-=zs;
					cnt++;
					js=1;
				}
				if(n/2+zs/(a[2]-a[1])<=n){
					m-=zs;
					cnt++;
					js=1;
				}
				if(js==0){
					break;
				}
				zs+=(a[2]-a[1]);
			}else{
				if(m>=zs&&(n/2+zs/(a[2]-a[1])<=n||n/2-zs/(a[2]-a[1])>=1)){
					m-=zs;
					cnt++;
				}else{
					break;
				}
				break;
			}
		}
		cout<<cnt;
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int cnt=1;
		int l=i-1,r=i+1;
		int zm=m;
		while(1){
		if(l>=1&&r<=n){
			int ls=abs(a[l]-a[i]),rs=abs(a[r]-a[i]);
			if(ls>=rs){
				if(zm>=rs){
					zm-=rs;
					r++;
					cnt++;
				}else{
					break;
				}
			}else{
				if(zm>=ls){
					l--;
					zm-=ls;
					cnt++; 
					}else{
						break;
					}
				}
			}else if(l>=1&&r>n){
				int ls=abs(a[l]-a[i]);
				if(zm>=ls){
					l--;
					zm-=ls;
					cnt++;
				}else{
					break;
				}
			}else if(l<1&&r<=n){
				int rs=abs(a[r]-a[i]);
				if(zm>=rs){
					r++;
					zm-=rs;
					cnt++;
				}else{
					break;
				}
			}
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	
	
	return 0;
}
