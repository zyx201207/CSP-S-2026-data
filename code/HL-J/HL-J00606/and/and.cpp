#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,w[2000100],m,f[2000100];
bool A=1;
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<n+1;i++){
		cin>>w[i];
		if((w[i]+1)%2!=0){
			A=0;
		}
	}
	sort(w+1,w+n+1,cmp);
	if(m==1){
		cout<<w[1];
		return 0;
	}
	if(A){
		cout<<w[m];
		return 0;
	}
	if(m==n){
		ll num=0;
		for(int i=1;i<n+1;i++){
			num&=w[i]; 
		}
		cout<<num;
		return 0;
	}
	if(m==2){
		ll num=0;
		for(int i=1;i<n+1;i++){
			for(int j=i+1;j<n+1;j++){
				num=max(num,w[i]&w[j]);
			}
		}
		cout<<num;
		return 0;
	}
	f[1]=w[1];
	for(int i=2;i<n+1;i++){
		for(int j=1;j<min((ll)(i+1),m+1);j++){
			f[j]=max(f[j],f[j-1]&w[i]);
		}
	}
	cout<<f[m];
	return 0;
}

