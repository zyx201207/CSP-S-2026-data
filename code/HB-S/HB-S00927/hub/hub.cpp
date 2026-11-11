#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv){
    //freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);
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
