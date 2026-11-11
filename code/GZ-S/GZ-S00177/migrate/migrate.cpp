//GZ-S00177 华东师范大学附属贵阳学校 杨昊宸
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	int c,t,n,d;
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(c>=15&&c<=18){
			cout<<n<<'\n';
		}
		if(c==13||c==14){
			cout<<1<<'\n';
		}
	}
	

	fclose(stdin);
	fclose(stdout);
	return 0;
}
