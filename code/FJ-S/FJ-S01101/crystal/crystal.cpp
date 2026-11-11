#include<bits/stdc++.h>
using namespace std;
long long n,m,f,maxn,cnt;
long long a[500005],box[205];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+1+n);
	if(n<=10000){
		for(int i=n;i>=1;i--){
			f=m;
			for(int j=1;j<=i;j++){
				f-=(a[i]-a[j]);
				if(f<0) break;
			}
			if(f>=0){
				cout<<i;
				return 0;
			}
		}
	}
	else if(maxn<=100){
		for(int i=1;i<=n;i++){
			box[a[i]+100]++;
		}
		for(int i=200;i>=0;i--){
			f=m;
			cnt=0;
			for(int j=0;j<=i;j++){
				f=f-(i-j)*box[i];
				if(f<0) break;
			}
			if(f>=0){
//				cout<<f<<endl;
//				cout<<i<<endl;
//				cout<<box[i+1]<<endl;
//				cout<<box[i]<<endl;
				for(int j=i;j>=0;j--){
					if(j!=0){
						cnt+=box[j];
					}
					else{
						cnt=cnt+f/i;
					}
				}
				cout<<cnt;
				return 0;
			}
		}
		
	}
	else{
		for(int i=n;i>=1;i--){
			m-=(a[n]-a[i]);
			if(m<0){
				cout<<n-i;
				return 0;
			}
		}
		cout<<n;
	}
	
	
	return 0;
}
