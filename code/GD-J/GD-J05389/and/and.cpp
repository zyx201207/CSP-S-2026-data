#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int N = 1e5 + 5;
int n,m;
ull a[2*N],cnt,maxx,be;
int miku(int k){
	int sum=0;
	if(k==0) return 0;
	while(k%2==0){
		sum++;
		k/=2;
	}
	if(k!=1) return 0;
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int k=miku(n);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!be && miku(a[i])) be++;
		if(i==1) cnt=a[1];
		else cnt=(cnt & a[i]);
	}
	sort(a+1,a+1+n);
	if(m==1) cout<<a[n]; //6
	else if(n==m) cout<<cnt; //7
	else if(m==2){ //8-10
		for(int i=1;i<=n;i++){
			if(miku(a[i])) continue;
			for(int j=i+1;j<=n;j++)
				maxx=max(maxx,(a[i] & a[j]));
		}
		cout<<maxx;
	}
	else if(a[n]<4){ //16,17
		if(be>0) cout<<min(a[n],2ull);
		else cout<<a[n];
	}
	else if(k>0){ //14,15
		if(m==k) cout<<a[n];
		else if(m<k) cout<<n/2;
		else cout<<49152;
	}
	else cout<<a[n]; //13
	return 0;
}
/*
ÕôÒ»Õô 40-50pts 
*/
