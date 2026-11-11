#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ma=-1;
ll lst[5000005];
ll l,r=0;
ll G_(ll n){
	ll num=1;
	for(int q=n;q>=2;q++){
		num+=q;
	}return num;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","W",stdout);
	cin>>n>>m;
	ll s;ll z;
	for(int i=0;i<n;i++){
		cin>>lst[i];
		if(i==1){
			l=lst[i]-lst[i-1];
		}else if(l!=lst[i]-lst[i-1]){
			r=1;
		}
	}
	
	sort(lst,lst+n);
	for(ll i=n-1;i>=1;i--){
		ll s=m;
		ll z=0;
		for(ll j=i-1;j>=0;j--){
			if(s-(lst[i]-lst[j])>=0){
				z=z+1;//此处没加上 
				s=s-(lst[i]-lst[j]);//此处没减去 
			}else {
				break;

			}	
		}
		ma=max(ma,z+1);
	}cout<<ma;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
