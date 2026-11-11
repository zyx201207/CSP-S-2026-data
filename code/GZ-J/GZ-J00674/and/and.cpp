//GZ-J00674兴义市弘毅中学龙家仁
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans,nm=-1,o=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(long long i = 0;i<n;i++){
		cin>>a[i];
		nm=max(a[i],nm);
		o=o&a[i];
	}
	if(m==1){
		cout<<nm;
		return 0;
	}
	if(m==n){
		cout<<o;
	}
	for(long long i =0;i<(1<<n);i++){
		nm=1;
		for(long long j = 0;j<n;j++){
			for(long long l = 0;l<m;l++){
			if(i&(1<<j)){
				nm=a[j]&a[j+1];
				ans=max(nm,ans);
			}
		}
		nm=1;
		}
	}
	cout<<ans;
	return 0;
} 
