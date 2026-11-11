#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200020];
vector<int>choose;
int zhi;
int ff=1;
void suan(){
	zhi=choose[0];
	for(int i=1;i<(int)choose.size();i++){
		zhi&=choose[i];
	}
}bool check(){
	for(int i=1;i<=21;i++){
		if(pow(2,i)==n){
			zhi=i;
			return true;	
		}
	}return false;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=4)ff=0;
	}int ans=0;
	if(ff){
		int c1=0,c2=0,c3=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)c1++;
			if(a[i]==2)c2++;
			if(a[i]==3)c3++;
		}if(m<=c1+c3)cout<<3;
		else cout<<2;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}cout<<ans;
		return 0;
	}if(check()){
		zhi++;
		if(m<zhi)cout<<n-1;
		else{
			m=m-zhi+1;
			for(int i=1;i<=30;i++){
				if(m-(zhi-i)*pow(2,i)<zhi){
					cout<<n-pow(2,i+2);
					return 0;
				}
			} 
		}
		return 0;
	}if(m==n-1){
		int nows=1,maxn=0;;
		for(int i=1;i<=n;i++){
			int ma=0,cnt=0;
			int now=a[i];
			while(now>=1){
				if(now%2==0)ma+=pow(2,cnt);
				cnt++;
				now>>=1;
			}if(ma>maxn)nows=i;
		}for(int i=1;i<=n;i++){
			if(nows==i)continue;
			ans&=a[i];
		}cout<<ans;
		return 0;
	}
	for(int i=1;i<=(1<<n);i++){
		int cnt=1,now=i;
		while(now>=1){
			if(now%2)choose.push_back(a[cnt]);
			cnt++;
			now>>=1;
		}if(choose.size()==m){
			suan(),ans=max(ans,zhi);
		}
		choose.clear();
	}cout<<ans;
	return 0;
}
