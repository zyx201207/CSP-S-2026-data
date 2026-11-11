#include<bits/stdc++.h>
using namespace std;
long long che1,che2;
string a,b;
long long ans[5]={0};
long long pai1,pai2;
long long lie1,lie2;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>che1>>a>>che2>>b;
	pai1=(a[0]-'0')*10+a[1]-'0';
	pai2=(b[0]-'0')*10+b[1]-'0';
	lie1=a[2];
	lie2=b[2];
	if(che1==che2) {
		ans[1]=1;
		if(pai1==pai2) {
			ans[2]=1;
			if((lie1>='A' and lie1<='C' and lie2>='A' and lie2<='C') or (lie1>='D' and lie1<='F' and lie2>='D' and lie2<='F') ) {
				ans[3]=1;
				if(lie1+1==lie2 or lie2+1==lie1){
					ans[4]=1;
				}
			}
		}
	}
	for(int i=1;i<=4;i++){
		cout<<ans[i];
	}








	return 0;
}
