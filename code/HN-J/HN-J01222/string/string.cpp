#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[1000000010],b[100000010],ans=0;
	string m;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
	}
	for(long long i=1;i<=a[i];i++){
		for(long long j=1;j<=a[i];j++){
			m+=b[i];
		}
	}
	for(long long l=0;l<m.size();l++){
		for(long long r=m.size();r>0;r--){
			if(m[l]!=m[r]){
				m[r]==m[l];
				ans++;
			}
			if(l==r){
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
