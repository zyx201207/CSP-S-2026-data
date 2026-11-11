//GZ-J00541 兴义市弘毅中学 刘桐瑞
#include<bits/stdc++.h>
using namespace std;
long long n,a[1000000],m,zc,zd,pd;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=1;i<=(1<<n);i++){
		for(int j=0;j<n;j++){	
		vector<long long> v;
		pd=0;
		if(i%(1<<j)){
		v.push_back(a[j]);
		if(pd==0){
			zc=a[j]&a[j];
		}else{
				zc&=a[j];
		}
		}
	if(v.size()==m){
		if(zc>zd){
			zd=zc;
		}
	
	}
	}
}
	cout<<zd;
	cout<<'\n';
	return 0;
} 
