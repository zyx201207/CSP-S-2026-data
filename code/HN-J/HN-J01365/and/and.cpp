#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000000],s[10000000],ma,sum,ans,an[10000000],o;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	int x;
    	cin>>x;
    	int sum=0;
    	while(x>0){
    		sum++;
    		s[sum]=x%2;
    		x/=2;
		}
		int p=1;
		ma=max(ma,sum);
		for(int j=1;j<=sum;j++){
			a[i]+=s[j]*p;
			p*=10;
		}
	}
	
	int p=1;
	for(int i=1;i<ma;i++){
		p*=10;
	}
	int maa=ma;
	for(int i=1;i<=maa;i++){
		ans=0;
        for(int j=i;j<=n;j++){
        	if(a[j]/p==1) ans++;
		}
		if(ans>=m) break;
		p/=10;
		ma--;
	}
	int tot=0;
	for(int i=1;i<=n;i++){
		if(a[i]/p==1) an[++tot]=a[i];
	}
	
	for(int i=1;i<=ma;i++){
		bool kk=1;
		for(int j=1;j<=m;j++){
			if(an[j]%(p*10)/p==0) kk=0;
		}
		o+=kk*p;
		p/=10;
	}
	int q=1,l=0;
	for(int i=1;i<=ma;i++){
		l+=o%10*q;
		q*=2;
		o/=10;
	}
	cout<<l;
	return 0;
} 
