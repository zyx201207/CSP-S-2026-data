#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N=2e5+5;
long long n,m;
long long a[N],b[N];
long long ans=-1;
bool cmp(long long x,long long y){
	return x>y;
}
void scr(long long r,long long id,long long num){
	bool flag=0;
	long long maxt=-1;
	if(r==1){
		cout<<num;
		return;
	}
	for(int i=id;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(b[j]==0)continue;
			maxt=max(maxt,b[i]&b[j]);
			if((b[i]&b[j])==b[j] && b[j]!=0){
				id=j;
				flag=1;
				//cout<<r<<" "<<maxt<<" "<<id<<endl;
				break;
			}
		}
		if(flag)break;
	}
	num&=maxt;
	//cout<<r<<" "<<num<<" "<<id<<endl;
	scr(r-1,id,num);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n+1,cmp);
	if(m==1){
		cout<<b[1];
		return 0;
	}else if(m==n){
		ans=b[1];
		for(int i=2;i<=n;i++){
			ans&=b[i];
		}
		cout<<ans;
		return 0;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,b[i]&b[j]);
				if((b[i]&b[j])==b[j])goto lout;
				//cout<<max(ans,b[i]&b[j])<<endl;
			}
		}
		lout:
		cout<<ans;
		return 0;
	}else{
		scr(m,1,-1);
	}
	return 0;
}
