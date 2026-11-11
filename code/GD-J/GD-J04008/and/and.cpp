#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=2e5+10;
ll n,m,a[N],f[N],maxx;
bool cmp(ll x,ll y){
	return x>y;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[1];return 0;
	}
	for(int i=1;i<=m;i++){
		if(maxx==0){
			ll temp=a[i],flag=0;
			while(temp>1){
				if(temp%2!=0){
					flag=1;break;
				}
				temp/=2;
			}
			if(flag==1) maxx=a[i];
		}
		else{
			ll temp=maxx;
			temp=temp&a[i];
			if(temp==0){
				m++;continue;
			}
			else maxx=maxx&a[i];
		}
	}
	cout<<maxx;
	return 0;
}
