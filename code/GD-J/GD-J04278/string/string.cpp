#include<bits/stdc++.h>

using namespace std;
int n;
int qq[210000];
char a[210000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>qq[i]>>a[i];
	}
	int l=1,r=n;
	long long ans=0;
	while(l<r){
		if(a[l]==a[r]){
			if(qq[l]>qq[r]){
				qq[l]-=qq[r];--r;
			}else if(qq[l]==qq[r]){
				++l;--r;
			}else{
				qq[r]-=qq[l];++l;
			}
		}else{
			if(qq[l]>qq[r]){
				ans=ans+qq[r];
				qq[l]-=qq[r];--r;
			}else if(qq[l]==qq[r]){
				ans=ans+qq[l];
				++l;--r;
			}else{
				ans=ans+qq[l];
				qq[r]-=qq[l];++l;
			}
		}
	}
	cout<<ans;
	return 0;
}/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/ 
