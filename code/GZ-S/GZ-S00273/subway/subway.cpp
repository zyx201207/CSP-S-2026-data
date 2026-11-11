//GZ-S00273 贵阳市第三中学 张轩哲 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,c,d,T,a[N],s[N],ti,x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>s[j]>>ti;
		}
	}
	while(T--){
		cin>>x>>y;
	}
	
	return 0;
}
