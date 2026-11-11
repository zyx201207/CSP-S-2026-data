#include<bits/stdc++.h>
using namespace std;
int n;
char c[200005];
int cnt[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long l=1,r=0,ans=0;
	for(int i=1;i<=n;i++){
		cin>>cnt[i]>>c[i];
		r+=cnt[i]; 
	}
	int i=1,j=n;
	for(;l<=r;){
		if(l==r||i==j) break;
		int x=min(cnt[i],cnt[j]);
		if(c[i]==c[j]){
			l+=x,r-=x;
			int a=x;
			if(cnt[i]-a>0){
				cnt[i]-=a; 
			}
			else {
				while(cnt[i]-a<=0){
					cnt[i]-=a;
					a=-cnt[i];
					i++;
				}
			}
			a=x;
			if(cnt[j]-a>0){
				cnt[j]-=a; 
			}
			else {
				while(cnt[j]-a<=0){
					cnt[j]-=a;
					a=-cnt[j];
					j--;
				}
			}
		}else if(c[i]!=c[j]){
			ans+=x;
			l+=x,r-=x;
			int a=x;
			if(cnt[i]-a>0){
				cnt[i]-=a; 
			}
			else {
				while(cnt[i]-a<=0){
					cnt[i]-=a;
					a=-cnt[i];
					i++;
				}
			}
			a=x;
			if(cnt[j]-a>0){
				cnt[j]-=a; 
			}
			else {
				while(cnt[j]-a<=0){
					cnt[j]-=a;
					a=-cnt[j];
					j--;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
