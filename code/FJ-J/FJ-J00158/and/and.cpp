#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int maxans=INT_MIN;
int ok=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
		if(a[i]!=i-1){
			ok=0;
			break;
		}
	if(m==1){
		for(int i=1;i<=n;i++)maxans=max(maxans,a[i]);
		cout<<maxans;
	}else if(m==n){
		maxans=a[1];
		for(int i=2;i<=n;i++)maxans=maxans&a[i];
		cout<<maxans;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxans=max(maxans,a[i]&a[j]);
			}
		}
		cout<<maxans;
	}else if(m==n-1){
		int maxx=a[1];
		for(int i=2;i<=n;i++){
			for(int j=2;j<=n;j++){
				if(i==j)continue;
				maxx=maxx&a[i];
			}
			maxans=max(maxans,maxx);
		}
		cout<<maxx;
	}else if(ok==0){
			int minn=INT_MAX; 
			int anss=0;
			for(int i=1;i<=n;i++)minn=min(minn,a[i]);
			int logg=minn+1;
			while(logg!=1){
				logg/=2;
				anss++; 
			}
			cout<<anss;
	}else if(ok==1){
		if(n==1)cout<<0;
		else cout<<1;
	}else{
		int okk=1;
		int okkyi=1;
		int okksan=1;
		for(int i=1;i<=n;i++){
			if(a[i]==2)okk=0;
			if(a[i]==1)okkyi=0;
			if(a[i]==3)okksan=0;
		}
		if(okk==1){
			if(okkyi==1){
				cout<<3;
			}else{
				cout<<1;
			}
		}else{
			if(okkyi==1)cout<<2;
			else cout<<0;
		}
	}
	return 0;
} 
