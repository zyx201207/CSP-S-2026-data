#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int a[MAXN];
int lowbit(int x){
	return x&(-x);
}
int fh(int x){
	int tt=31;
	while(tt>0){
		if(pow(2,tt)<=x)break;
		tt--;
	}
	return tt;
}
bool fd(int x,int s){
	int lx,ss=pow(2,s-1);
	if(x<ss)return false;
	while(x>0){
		lx=x&(-x);
		if(lx==ss)return true;
		if(lx>ss)return false;
		x-=lx;
	}
	return false;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,mx=INT_MIN;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]>mx)mx=a[i];
	}
	int f,t,ans=0;
	vector<int>v;
	for(int i=fh(mx);i>=1;i--){
		t=i;
		v.clear();
		f=0;
		for(int j=1;j<=n;j++){
			if(fd(a[j],i)){
				f++;
				v.push_back(j);
			}
		}
		if(f>=m){
			break;
		}
	}
	if(f<m){
		cout << ans;
		return 0;
	}
	else{
		ans+=pow(2,t-1);
		vector<int>q;
		for(int i=t-1;i>=1;i--){
			q.clear();
			f=0;
			for(int j=0;j<v.size();j++){
				if(fd(a[v[j]],i)){
					f++;
					q.push_back(v[j]);
				}
			}
			
			if(f>=m){
				ans+=pow(2,i-1);
				v.clear();
				for(int j=0;j<q.size();j++){
					v.push_back(q[j]);
				}
			}
		}
		cout << ans;
	}
	return 0;
}
