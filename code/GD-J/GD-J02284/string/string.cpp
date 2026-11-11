#include<bits/stdc++.h>
using namespace std;
#define int long long
struct u {
	char c;
	int num;
};
int n;
u a[200010];
int l=1,r;
int lk=0,rk=0;
int ans=0;
int sum=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
		sum+=a[i].num;
	}
	sum/=2;
	r=n;
	while(lk<sum&&rk<sum&&l<r){
		if(lk+a[l].num<=rk+a[r].num){
			while(lk+a[l].num<=rk+a[r].num){
				if(a[l].c!=a[r].c)ans+=a[l].num; 
				lk+=a[l++].num;
			}
		}
		else{
			while(lk+a[l].num>=rk+a[r].num){
				if(a[l].c!=a[r].c)ans+=a[r].num; 
				rk+=a[r--].num;
			}
		}
		if(lk+a[l].num<rk+a[r].num&&a[r+1].num!=a[l].num){
			if(a[l].c!=a[r].c)ans+=rk+a[r].num-lk-a[l].num;
			lk+=a[l++].num;
		}else if(rk+a[r].num<lk+a[l].num&&a[r].num!=a[l-1].num){
			if(a[l].c!=a[r].c)ans+=lk+a[l].num-rk-a[r].num;
			rk+=a[r--].num;
		}
//		cout<<l<<" "<<r<<"\n";
	}
	cout<<ans;
	return 0;
}
