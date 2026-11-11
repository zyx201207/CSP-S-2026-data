//GZ-S00184 华东师范大学附属贵阳学校 袁琬潇 
#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
int c,t,n,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==0){
		while(t--){
			cin>>n;
			for(int i=1;i<=n;i++) cin>>a[i];
		}
	}
	return 0;
}
