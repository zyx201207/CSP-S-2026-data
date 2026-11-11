#include<bits/stdc++.h>
using namespace std;
#define int long long
long long n,num,sum,x[200010],a[200010],id,ml[2000010],mr[200010],l=1,r,ans,suml,sumr;
char c[200010];
long long f;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","r",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>c[i];
		sum+=x[i];
	}
	for(int i=1;i<=n;i++){
		num+=x[i];
		if(num>=sum/2&&f==0){
			id=i;
			f=1;
			ml[i]+=sum/2-(num-x[i]);
			mr[i+1]+=num-(sum/2);
			continue;
		}	
		if(f==0) ml[i]+=x[i];
		else mr[i]+=x[i];
	}
	suml=ml[1];
	sumr=mr[n];
	while(l<r){
		if(ml[l]>mr[r]){
			if(c[l]!=c[r]){
				ans+=mr[r];
			}
			ml[l]-=mr[r];
			r--;	
			sumr+=mr[r];		
		}else if(ml[l]<mr[r]){
			if(c[l]!=c[r]){
				ans+=ml[l];
			}
			mr[r]-=ml[l];
			l++;	
			suml+=ml[l];
		}else{
			if(c[l]!=c[r]){
				ans+=mr[r];
			}
			r--;
			l++;	
			sumr+=mr[r];	
			suml+=ml[l];		
		}
	}
	cout<<ans;
	return 0;
}
