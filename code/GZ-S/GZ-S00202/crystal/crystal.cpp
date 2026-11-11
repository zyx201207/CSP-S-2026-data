//GZ-S00202 贵阳市第一中学 薛子彦 
#include<iostream>
#include<algorithm>
using namespace std;
int n;
long long m,a[500010],s[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=a[i]+s[i-1];
	for(int i=n;i>=1;i--){
		for(int j=1;i+j-1<=n;j++){
			//i为长度，j为起点
			if(a[i+j-1]*i-s[i+j-1]+s[j-1]<=m){
				cout<<i<<endl;
				return 0;
			}
		}
	}
	return 0;
}
