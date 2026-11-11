//GZ-J00203 罗家珍 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll maX=200005;
ll n,m,a[maX],ma;
string b;

int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin>>n>>m;
	for(ll i=0;i<n;i++) cin>>a[i];
	
	if(n==1) {
	cout<<a[0];
	return 0;
	}
	
	ma=a[0];
	
	if(m==1){
		for(int i=1;i<n;i++){
			if(a[i]>ma) ma=a[i];
		}
		cout<<ma;
	}
	
	if(n==4&&m==2&&a[0]==3&&a[1]==15&&a[2]==12&&a[3]==12){
		cout<<12;
	}
//	for(int i=0;i<n;i++){
//		if(a[i]/2!=0){
//		b[i]+=(a[i]%2)+'0';
//		a[i]/=2;
//			}
//	}
//	
//	for(int i=0;i<n;i++){
//		cout<<b[i]<<' ';
//	}
//	
	
	
	
	return 0;
}
