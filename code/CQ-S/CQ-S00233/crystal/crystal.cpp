#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],d[500005],sum,cnt,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum=m,cnt=0;
		long long l=i,r=i+1;
		while(l>=0&&r<=n+1&&sum>0){
			if(l==0&&r==n+1) break;
			else if(l==0){
				if(sum-abs(a[r]-a[i])>=0){
					cnt++;
					sum-=abs(a[r]-a[i]);
					r++;
				}else{
					break;
				}
			}else if(r==n+1){
				if(sum-abs(a[l]-a[i])>=0){
					cnt++;
					sum-=abs(a[l]-a[i]);
					l--;
				}else{
					break;
				}
			}else{
				if(abs(a[r]-a[i])>abs(a[l]-a[i])){
					if(sum-abs(a[l]-a[i])>=0){
						cnt++;
						sum-=abs(a[l]-a[i]);
						l--;
					}else{
						break;
					}
				}else{
					if(sum-abs(a[r]-a[i])>=0){
						cnt++;
						sum-=abs(a[r]-a[i]);
						r++;
					}else{
						break;
					}
				}
			}
		}ans=max(ans,cnt);
	}cout<<ans;
	return 0;
}
//5 5
//1 2 4 8 9
//
//1 3 7 8

//5 8
//-3 -1 2 2 7
//
//2 5 5 10
//2 7 12 22


