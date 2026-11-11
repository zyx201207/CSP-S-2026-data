#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[200005],s=INT_MIN;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i==1){
				s=max(s,a[j]&1);
			}else{
				s=max(s,s%a[j]);
			}
		}
	}
	cout<<s;
	return 0;
}

