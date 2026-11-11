#include<bits/stdc++.h>
using namespace std;
int cnt(int be,int en,int b){
	int d=en-be;
	if(d>b&&d&1)return 1;
	else return 0;
}
void func(){
	long long n,d,ans=0;
	cin>>n>>d;
	long long a[2000005],diff[2000005];
	memset(diff,0,sizeof(diff));
	int t = 1;
	cin>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		diff[i] = a[i]-a[i-1];
		if(diff[i]!=diff[i-1]&&i>2){
			t=0; 
		}
	}
	if(n<=3){
		cout<<0<<endl;
		return ;
	}
	if(t){
		if(diff[2]>=d){
			cout<<0<<endl;
			return ;
		}
		for(int i=2;i<=n;i++){
			if(cnt(a[1],a[i],d)){ans+=n-i+1;break;}
			}
		}
//	else {
		//for(int i=2;i<=n;i++){
			//for(int j=1;j<i;j++){
				//if(add(a[i]-a[j],d)==2)ans++;
			//}
		//}
	//}
	cout<<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		func();
	}
	return 0;
}
