#include<bits/stdc++.h>
using namespace std;
long long mm,m,s,n,a[500005],mx=-1e14,gc;bool bb=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];
		if(bb){
		if(i==2)gc=a[i]-a[i-1];
		else if(i>2)if(a[i]-a[i-1]!=gc)bb=false;
		}
	}
	sort(a+1,a+n+1);
	if(bb){long long k=m/gc;
		for(s=1;s*s<=2*k-s;s++);
		cout<<s;return 0;
	}
	long long t=2;mm=m;
	for(int i=1;i<=n;i++){
		m=mm;s=1;t=2;
		while(m>=0&&s<=n){
			//cout<<m<<" "<<s*(a[t]-a[t-1])<<endl;
			if(m-s*(a[t]-a[t-1])<0)break;
			m-=s*(a[t]-a[t-1]);t++;s++;
		}
		mx=max(mx,s);
	}
	cout<<mx;
	return 0;
}
