#include<bits/stdc++.h>
using namespace std;
int a[200005]={0};
int zhuan(int d){//求有多少1 
	int i=1;
	int num=0;
	for(;d!=0;){
		i=1;
		for(;i<=d;i*=2);
		i/=2;
		d-=i;
		num++;
	}
	return num;
}
int foud(int a[200005], int n, int m, int ans){
	int d=0;
	int big=0;
	for(int i=0;i<n;i++){
		if(zhuan(a[i])>d){
			big=i;
			d=zhuan(a[i]);
		}
	}
	ans = a[big];
	a[big]=0;
	for(int i=0;i<m-1;i++){
		big=0,d=0;
		for(int i=0;i<n;i++){
			if(zhuan(a[i])>d){
				big=i;
				d=zhuan(a[i]);
				
			}
		}
		
		ans = ans&a[big];
//		cout<<a[big]<<" "<<ans<<endl;
		a[big]=0; 
	}
	return ans;
}
int main(){//暴力拿60 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n=0,m=0;
	cin>>n>>m;
	int ma=0;
	int nnn=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
//		cout<<i<<" "<<n<<endl;
		if(i==0){
			nnn=a[i];
		}
		else{
			nnn=nnn & a[i];
		}
		ma = max(a[i], ma);
	}
	if(m==1){
		cout<<ma;
		return 0;
	}
	if(m==n){
		cout<<nnn;
		return 0;
	}
	if(m==2){
		ma=0;
		for(int i=0;i<n;i++){
			for(int j=1;j<n;j++){
				if(i!=j){
					ma = max(ma,a[i] & a[j]);
				}
			}
		}
		cout<<ma;
		return 0;
	}
	int ans=0;
	ma=0;
	ans = foud(a,n,m,ma);
	cout<<ans;
	return 0;
}
