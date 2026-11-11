#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);	
	long long n,m;
	cin>>n>>m;
	long long q[n+1];
	long long maxn=0;
	for(int i=1;i<=n;i++){
		cin>>q[i];
		maxn=max(maxn,q[i]);
	}
	long long sum=0;
	for(int i=1;i<=n;i++){
		sum+=maxn-q[i];
	}	
	long long zjz=sum/m;
	int cnt=0;
	int maxn1=0;	
	if(m>=sum){
		cout<<n;
	}
	else{
		if(q[1]>0){
			for(long long i=1;i<=m;i++){
				if(m>=(zjz-q[i])){
					cnt++;	
					if(zjz-q[i]<0){
						continue;
					}
					else{
						m-=(zjz-q[i]);
					}
					maxn1=max(maxn1,cnt);
				}
			}	
			cout<<maxn1+1;
		}
		else{
			for(long long i=1;i<=m;i++){
				if(m>=(zjz-q[i])){
					cnt++;	
					if(zjz-q[i]<0){
						continue;
					}
					else{
						m-=(zjz-q[i]);
					}
					maxn1=max(maxn1,cnt);
				}
			}	
			cout<<maxn1+3;			
			
			
		}
		
	}
	
	return 0;
}
