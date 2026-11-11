#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int m;
int a[500005];
int d[500005];
int id[500005];
map<int,int>mp;
bool fa=1;
bool fb=1;
bool cmp(int x,int y){
	return mp[x]>mp[y];
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)fa=0;
		mp[a[i]]++;
	}
	if(fa){
		int ans=1;
		for(int i=2;i<=n;i++){
			if(m>=i*(i-1)/2)ans=i;
		}
		cout<<ans;
	}
	else if(fb){
		int sb=a[2]-a[1];
		int ans=1;
		for(int i=2;i<=n;i++){
			if(m>=sb*i*(i-1)/2)ans=i;
		}
		cout<<ans;
	}
	else{
		sort(a+1,a+n+1);
		int newn=unique(a+1,a+n+1)-a-1;
		for(int i=1;i<=newn;i++){
			d[i]=a[i];
			id[a[i]]=i;
		}
		sort(d+1,d+newn+1,cmp);
		int ans=1;
		for(int i=1;i<=newn;i++){
			int pre=-1,suf=newn+1;
			int newm=m;
			int res=mp[d[i]];
			if(id[d[i]]-1>0)pre=id[d[i]]-1;
			if(id[d[i]]+1<=newn)suf=id[d[i]]+1;
			while(newm>0&&(pre>=1||suf<=newn)){
				int sb=newm;
				if(pre>=1&&(suf>newn || ((d[i]-a[pre])<=(a[suf]-d[i])))){
					if(newm-mp[a[pre]]*(d[i]-a[pre])>=0){
						res+=mp[a[pre]];
						newm-=mp[a[pre]]*(d[i]-a[pre]);
					}else{
						res+=(newm/(d[i]-a[pre]));
						newm-=(newm/(d[i]-a[pre]))*(d[i]-a[pre]);
					}
					pre--;
				}	
				else if(suf<=newn&&(pre<1 || (d[i]-a[pre])>(a[suf]-d[i]) )){
					if(newm-mp[d[i]]*(a[suf]-d[i])>=0){
						res+=mp[d[i]];
						newm-=mp[d[i]]*(a[suf]-d[i]);
					}else{
						res+=(newm/(a[suf]-d[i]));
						newm-=(newm/(a[suf]-d[i]))*(a[suf]-d[i]);
					}
					suf++;
				}
			if(sb==newm)break;
			}
			ans=max(ans,res);
			//cout<<res<<" ";
		}
		cout<<ans;
	}
	return 0;
	
}
//5 8
//-3 -1 2 2 7

