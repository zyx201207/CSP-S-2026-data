#include<bits/stdc++.h>
using namespace std;
int a[200010];
bitset<200010>bs[50],tmp,tmp2;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=30;j>=0;j--){
			if((a[i]>>j)&1)bs[j][i]=1;
		}
		tmp[i]=1;
	}
	for(int i=30;i>=0;i--){
		tmp2=tmp&bs[i];
		if(tmp2.count()>=m)ans+=(1<<i),tmp=tmp2;
	}
	cout<<ans<<endl;
	return 0;
}

