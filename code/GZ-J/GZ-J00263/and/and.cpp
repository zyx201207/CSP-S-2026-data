/*GZ-J00263 贵阳市第二实验中学 莫卓均*/ 
#include<bits/stdc++.h>
using namespace std;
int a,s,d,f[100001],cs=1,ans,b,z[100001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>s;
	for(int i=1;i<=a;i++){
		cin>>f[i];
	}
	for(int i=1;i<=a;i++){
		for(int j=i;j<=a;j++){
			ans=f[i]&&f[j];
			d=max(d,ans);
		}
	}
	cout<<d; 
	return 0;
}
