#include<bits/stdc++.h>
using namespace std;
const int maxn=5e+5;
long long n,m,a[maxn],ans=1,cha[maxn],minc,mincp;
bool to(long long x,long long y){
	if(x==1)return 1;
	else if(y==n+1)return 0;
	else if(cha[x]<=ans*cha[y])return 0;
	else return 1;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	minc=a[2]-a[1];
	mincp=2;
	for(int i=2;i<=n;i++){
		cha[i]=a[i]-a[i-1];
		if(cha[i]<minc){
			minc=cha[i];
			mincp=i;
		}
	}
	int l=mincp,r=mincp+1;
	while(m){
		if(m==0){cout<<ans;return 0;}
		if(l==1&&r==n+1&&m>0&&m%n==0){cout<<n;return 0;}
		if(l==1&&r==n+1&&m>0&&m%n!=0){cout<<n-1;return 0;}
		if(l==1&&r==n+1&&m<=0){cout<<n;return 0;}
		if(cha[l]==0&&l!=1){l--;ans++;continue;}
		if(cha[r]==0&&r!=n+1){r++;ans++;continue;}
		if(!to(l,r)){
			if(m<cha[l]){cout<<ans;return 0;}
			m-=cha[l];
			cha[l-1]+=cha[l];
			cha[l]=0;
			l--;
			ans++;
		}
		else{
			if(m<ans*cha[r]){cout<<ans;return 0;}
			m-=ans*cha[r];
			cha[l]=a[r]-a[l-1];
			cha[r]=0;
			r++;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
