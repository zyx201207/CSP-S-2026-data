#include <bits/stdc++.h>
using namespace std;
long long n,m,a,lz,s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		for(int i=1;i<=n;i++){
			cin>>a;
			if(lz<a){
				lz=a;
			}
		}
		cout<<lz;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			cin>>a;
			if(lz<a){
				s=lz;
				lz=a;
			}else if(s<a){
				s=a;
			}
		}
		cout<<s;
	}
	return 0;
}
