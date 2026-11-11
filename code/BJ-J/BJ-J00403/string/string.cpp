#include<bits/stdc++.h>
using namespace std;
struct chuan{
	int d;
	char s;
};
chuan c[200005],a[200005],b[200005];
long long n,q,ans;
int ad=1,bd=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i].d>>c[i].s;
		q+=c[i].d;
	}
	q/=2;
	int i=0;
	while(1){
		i++;
		if(q<=c[i].d){
			a[ad].d=q;
			a[ad++].s=c[i].s;
			c[i].d-=q;
			break;
		}
		a[ad].d=c[i].d;
		a[ad++].s=c[i].s;
		q-=c[i].d;
	}
	b[bd].d=c[i].d;
	if(b[bd].d){
		b[bd].s=c[i].s;
		bd++;
	}
	i++;
	for(;i<=n;i++){
		b[bd].d=c[i].d;
		b[bd++].s=c[i].s;
	}
	i=1;
	while(bd && i<=ad){
		if(a[i].s!=b[bd].s){
			if(a[i].d>b[bd].d){
				ans+=b[bd].d;
				a[i].d-=b[bd].d;
				bd--;
			}
			else{
				ans+=a[i].d;
				b[bd].d-=a[i].d;
				i++;
			}
		}
		else{
			if(a[i].d>b[bd].d){
				a[i].d-=b[bd].d;
				bd--;
			}
			else{
				b[bd].d-=a[i].d;
				i++;
			}
		}
	}
	cout<<ans;
	return 0;
}
