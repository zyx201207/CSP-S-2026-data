#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],k,b[500005],op,ans=1,pan1,pan2;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==i){
			pan1++;
		}
	}
	if(pan1==n){
		while(m>0 && ans<n){
			op++;
			if(m>=op){
				m-=op;
				ans++;
			}else{
				cout<<ans;
				return 0;
			}
		}
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		b[i-1]=abs(a[i]-a[i-1]);
		if(i!=2 && b[i-1]==b[i-2]){
			pan2++;
		}
	}
	if(pan2==n-2){
		while(m>0 && ans<n){
			op+=b[3];
			if(m>=op){
				m-=op;
				ans++;
			}else{
				cout<<ans;
				return 0;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<n;i++){
		for(int j=i;j<n;j++){
			op+=a[j]*(j-i+1);
			if(op>m){
				k=j-i;
				op=0;
				break;
			}
		}
		if(k>ans){
			ans=k;
		}
	}
	cout<<ans;
	return 0;
} 
