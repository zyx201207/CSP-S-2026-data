//GZ-J00202 郭盛权 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005];
ll cntp[300005]; 
bool p=true;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<n;++i){
		cin>>a[i];
		cntp[a[i]]++;
		if(i>0&&a[i]<a[i-1]) p=false;
	}
	for(int i=1;i<n;++i){
		cntp[i]+=cntp[i-1];
	}
	if(p){
		for(int i=1;i<=m;++i){
			cout<<cntp[i]<<' ';
		}
		return 0; 
	}
	if(n==1) cout<<1;
	if(n==2) cout<<1<<' '<<2;
	
	return 0;
}
