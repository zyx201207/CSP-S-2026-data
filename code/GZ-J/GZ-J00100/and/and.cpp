//ÌÆÎÄ²©  GZ-J00100
#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
long long n,m,a[N],b[N],maxn;
int main(){
	freopen("and1.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(a[i],maxn);
	}
	if(m==1) {cout<<maxn;return 0;}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				b[i]=max(a[i]&a[j],b[i]);
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				b[i]=max(a[i]&a[j],b[i]);
			}
		}
		while(m--){
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					b[i]=max(b[i]&b[j],b[i]);
				}
			}
		} 
	}
	sort(b,b+n);
	cout<<b[n];
} 
