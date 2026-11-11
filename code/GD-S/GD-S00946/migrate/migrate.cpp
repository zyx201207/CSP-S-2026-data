#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,ans,num;unsigned long long d;long long in,first,second,third,last;
	cin>>c>>t;
	while(t--){
		ans=0;num=0;last=-1000000000000000005l,first=last,second=last,third=last;
		cin>>n>>d;
		while(n--){
			cin>>in;
			if((!num)||(in-last>d))num=0,last=-1000000000000000005l,first=last,second=last,third=last;
			num++;
			if(num==1)first=in,last=in;
			else if(num==2)second=in,last=in;
			else if(num==3){
				third=in,last=in;
				if(in-first>d)num=2,first=second,second=third;
			}
			else if(num==4&&in-first>d)ans++,last=in;
			else if(num>=4){
				if(last-first<=d&&third-first>d){
					second=third,third=last,last=in,num=4;
					if(last-first>d)ans++;
				}
				else if(last-first>d)ans++,first=second,second=third,third=last,last=in;
				else num=1,last=in,first=in,second=last,third=last;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
