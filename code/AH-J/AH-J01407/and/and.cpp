#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=2e+5;
long long a[N+10],n,m,maxn,x,sum,sum2,sum3,cs;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		if(i==1) sum2=a[i];
		else sum2&=a[i];
	}
	if(m==1){
		cout<<maxn;
		return 0;
	}
	else{
		if(m==2){
			for(int i=1;i<=n-1;i++){
				for(int j=i+1;j<=n;j++){
					x=(a[i]&a[j]);
					sum=max(sum,x);
				}
			}
			cout<<sum;
		}else{
			if(m==n){
				cout<<sum2;
			}else{
				if(m+1==n){
					for(int i=1;i<=n;i++){
						for(int j=1,cs=1;j<=n;j++,cs++){
							if(j!=i){
								if(cs==1) sum3=a[j];
								else sum3&=a[j];
							} 
						}
					}
					cout<<sum3;
				}
			}
		}
	}
	return 0;
}
