#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define ll long long
ll n,m,i,j,a[N],temp,d,maxb,maxc,cnt[40],cnt2[40],st;
bool zuihou=true;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=4) zuihou=false;
		if(i==1) maxc=a[i];
		else maxc=maxc&a[i];
		maxb=max(maxb,a[i]);
		temp=a[i],d=0;
		while(temp!=0){
			if(temp%2==0) cnt[d]++;
			d++;
			temp/=2;
		}
	}
	if(n<=20){
		ll maxa=-1e18,maxtemp;
		for(i=0;i<pow(2,n);i++){
			maxtemp=pow(2,40)-1;
			temp=i,d=0,st=0;
			while(temp!=0){
				d++;
				if(temp%2==1){
					st++;
					maxtemp=maxtemp&a[d];
				}
				temp/=2;
			}
			if(st==m) maxa=max(maxa,maxtemp);
		}
		cout<<maxa;
	}
	else if(n<=2000){
		if(m==1){
			cout<<maxb;
			return 0;
		}
		else if(m==n){
			cout<<maxc;
			return 0;
		}
		else if(m==2){
			ll maxd=-1e18;
			for(i=1;i<=n;i++){
				for(j=i+1;j<=n;j++){
					maxd=max(maxd,a[i]&a[j]);
				}
			}
			cout<<maxd;
			return 0;
		}
	}
	else{
		if(m==n-1){
			sort(a+1,a+n+1,greater<int>());
			ll maxe=0;
			temp=a[n],d=0;
			while(temp!=0){
				if(temp%2==1) cnt[d]--;
				temp/=2;
				d++;
			}
			for(j=0;j<=30;j++){
				if(cnt[j]==n-1){
					maxe+=pow(2,j);
				}
			}
			cout<<maxe;
		}
		bool p=true;
		for(i=1;i<=n;i++){
			temp=a[i]+1;
			while(temp!=1){
				if(temp%2==1){
					p=false;
					break;
				}
				else d++;
				temp/=2;
			}
			if(p==false) break;
			cnt2[d]++;
		}
		if(p){
			for(i=30;i>=1;i--){
				if(cnt2[i]>=m){
					cout<<pow(2,i)-1;
					return 0;
				}
			}
		}
		p=true;
		temp=n;
		while(temp!=1){
			if(p%2==1){
				p=false;
				break;
			}
			temp/=2;
		}
		if(p){
			temp=n/2;
			ll maxf=0;
			while(m<temp){
				maxf+=temp;
				temp/=2;
			}
			cout<<maxf;
			return 0;
		}
		if(zuihou){
			if(cnt[1]>=m&&cnt[2]>=m) cout<<3;
			else if(cnt[1]>=m&&cnt[2]<m) cout<<1;
			else if(cnt[1]<m&&cnt[2]>=m) cout<<2;
			else cout<<0;
			return 0;
		}
		cout<<0;
		return 0;
	}
	return 0;
}
