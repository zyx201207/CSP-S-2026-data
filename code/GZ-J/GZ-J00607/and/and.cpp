//GZ-J00607 刘祚诚 北京师范大学贵阳附属中学 
#include<bits/stdc++.h>
using namespace std;
const int N=1e8+5;
int n,m,a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ans=a[n];
	m--;
	for(int i=n-1;m>0;i--){
		if((ans&a[i])!=0)ans=(ans&a[i]),m--;
	}
	cout<<ans<<endl;
	return 0;
}

