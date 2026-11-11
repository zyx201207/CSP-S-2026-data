//start 14:36:48
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1],ans(0);
	for(int i(0);i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i(0),p;i<n;i++){
		int sum=1;
		p=m;
		for(int l(i-1),r(i+1);;){
//			cout<<l<<" "<<r<<" "<<i<<'\n';
			bool lok=0,rok=0;
			if(l>=0)lok=1;
			if(r<n)rok=1;
			int ls,rs;
			if(lok)ls=a[i]-a[l];
			if(rok)rs=a[r]-a[i];
			if(lok&&rok){
				if(ls<=rs&&ls<=p){
					l--,sum++,p-=ls;
				}else if(ls>rs&&rs<=p){
					r++,sum++,p-=rs;
				}else break;
			}else if(lok&&(!rok)){
				if(ls<=p)l--,sum++,p-=ls;
				else break;
			}else if((!lok)&&rok){
				if(rs<=p)r++,sum++,p-=rs;
				else break;
			}else break;
//			cout<<l<<" "<<r<<"  "<<i<<' '<<p<<'\n';
		} 
//		cout<<sum<<'\n';
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
} 
//蒜鸟 不会做 小数据过了一些
//end 14:55:12 
