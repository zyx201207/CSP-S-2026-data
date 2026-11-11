#include<bits/stdc++.h>
using namespace std;
struct acd{
	int a;
	char b;
};
int n;
acd a[200005] ;
long long cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int k=1;k<=n;k++)cin>>a[k].a>>a[k].b;
	int c=1,d=n;
	while(c<=d){
		if(a[c].b==a[d].b){
			if(a[c].a>=a[d].a){
				a[c].a-=a[d].a;
				d--;
			}else{
				a[d].a-=a[c].a;
				c++;
			}
		}else{
			if(a[c].a>=a[d].a){
				cnt+=a[d].a;
				a[c].a-=a[d].a;
				d--;
			}else{
				cnt+=a[c].a;
				a[d].a-=a[c].a;
				c++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
