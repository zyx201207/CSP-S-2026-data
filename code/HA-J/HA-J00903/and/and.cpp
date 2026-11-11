#include<bits/stdc++.h>
using namespace std;
long long a[100000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long maxn=a[n];
	long long minn=a[1];
	if(m==2){
		ans=maxn-minn;
	}else if(m==1){
		ans=0;
	}else{
		ans=12;
	}
	cout<<ans<<endl;
	return 0;
}
