#include <bits/stdc++.h>
using namespace std;
const int mxn=500010;
int b,i;
long long a[mxn],n,m,ans,as,all,num;
int main(int argc, char **argv){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	ans=1;
	for(int i=1;i<=n;i++){
		as=i;
		b=1;
		num=1;
		all=0;
		while(b){
			if(as-num==0)b=0;
			all+=a[as]-a[as-num];
			if(all>m){
				b=0;
				if(num>ans)ans=num;
			}
			else{
				num++;
			}
		}
	}
	cout<<ans;
}
