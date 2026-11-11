#include<bits/stdc++.h>
using namespace std;
#define unsigned long long int
const int N=5e5+5;
int a[N],s[N];
int cz[N];
int t,n,m;
int chuli(int a,int b){
	if(a==1)return s[b];
	else if(a>=b)return 0;
	else return chuli(a-1,b)+chuli(a,b-1)-chuli(a-1,b-1)-cz[b];
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	cz[1]=0;s[1]=0;
	for(int i=2;i<=n;i++){
		cz[i]=a[i]-a[i-1];
		s[i]=s[i-1]+(a[i]-a[i-1])*(i-1);
	}
	int p=0;
	for(int i=3;i<=n;i++){
		if(cz[i]==cz[i-1])p=1;
		else {p=0;break;}
	}
	if(p==1){
		for(int i=1;i<=n;i++){
			if((i*i+i)*0.5*cz[2]==m){
				cout<<i+1;return 0;
			}
		}
	}
	for(int l=1;l<=n-1;l++){
			for(int r=n;r>=l;r--){
				int k=chuli(l,r);
				if(k==m){cout<<r-l+1;return 0;}
			}
	}
	return 0;
}
