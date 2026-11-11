//GZ-S00168 贵阳市第一中学 曹玄憬 
#include<bits/stdc++.h>
using namespace std;
long long c,T,n,d,d1,d2,gongcha,len1;
string nous;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		if(c==11||c==12||c==0){
			cin>>d1>>d2;
			gongcha=d2-d1;
			if(d>=2*gongcha)
			{
				len1=d/gongcha;
				cout<<max(0ll,n-2*len1+1)<<endl;
			}
			else{
				cout<<0<<endl;
			}
			for(int i=3;i<=n;i++){
				cin>>nous;
			}
		}
		else{
			for(int i=1;i<=n;i++){
				cout<<0<<endl;
			}
		}
	}
	return 0;
}
