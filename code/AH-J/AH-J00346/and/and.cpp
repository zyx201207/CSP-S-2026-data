#include<bits/stdc++.h>
using namespace std;
long long a[1000010];
long long n,m,cnt;
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cnt=max(cnt,a[i]);
	}
	if(m==1){
		cout<<cnt;
	}else{
		cout<<cnt;
	}
	return 0;
}

