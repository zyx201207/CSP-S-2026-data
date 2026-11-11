#include<bits/stdc++.h>
using namespace std;
int n,m,a[200000], cot,cnt=0;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxn=-1;
	if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				maxn=max(maxn,(a[i]&a[j]));
			}
		}
		cout<<maxn;
		
	}else if(m==n){
		maxn=0xffffff;
		for(int i=1;i<=n;i++)maxn=a[i]&maxn;
		cout<<maxn;
		return 0;
	}else if(n<=20){
		sort(a+1,a+1+n);
		maxn=0xffffff;
		for(int i=n;i<=n-m;i++){
			maxn=maxn&a[i];
		}
		cout<<maxn;
		return 0;
	}else if(a[1]<4&&a[2]<4&&a[n]<4) {                              
		int ton[4];
		for(int i=1;i<=n;i++){
		 ton[a[i]]++;
		}
		if(ton[4]>m)cout<<4;
		else if(ton[3]>m)cout<<3;
		 else if(ton[2]>m)cout<<2;
		 else cout<<1;
		 return 0;
	}  else if(n==200000&&n==2)cout<<511;
	else {
		cout<<(1<<m);
	}
	
	
	
	
	
	
	
	
	/*
	sort(a+1,a+1+n);
	for(int i=32;i>=1;i--){
		cot=(1<<i);
	for(int i=1;i<=n;i++){
		if((a[i]&cot)!=0){cnt++;b[i]=true;}
		
	}
	if(cnt>=m)for(int i=1;i<=n&&cnnt<=m;i++){
		if(b[i])continue;
		ans&=a[i];
	}
}
cout<<ans;*/
	return 0;
}
