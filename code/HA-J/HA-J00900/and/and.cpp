#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],dp[200006];
int l,r;
bool f;
int p(int a,int b){
	while(a!=0){
		f=0;
		for(int i=a;i>=1;i--){
			if(pow(2,i)<=a){
				a-=pow(2,i);
				f=1;break;
			}
		}
		//cout<<"FEf\n";
		if(f==1){
			l*=10;
			l++;
		}else l*=10;
		a/=10;
	}
	f=0;
	
	while(b!=0){
		f=0;
		for(int i=b;i>=1;i--){
			if(pow(2,i)<=b){
				b-=pow(2,i);
				f=1;break;
			}
		}
		if(f==1){
			r*=10;
			r++;
		}else r*=10;
		b/=10;
	}
	int x=0,k=0;
	while(l!=0||r!=0){
		if(l%10==r%10){
			x++;
			x*=10;
		}else x*=10;
		l/=10;r/=10;
	}
	while(x!=0){
		k+=x%10;
		k*=10;
		x/=10;
	}
	return k;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//cout<<p(150,12);
	//cout<<(int)12&&15<<'\n';
	for(int i=1;i<=n;i++){
		dp[i]=-1;
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			int x=p(a[i],a[j]);
			dp[i]=max(dp[i],x);
		}
	}
	cout<<dp[m];
return 0;
}
