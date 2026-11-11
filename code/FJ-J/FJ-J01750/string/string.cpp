#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+5;
const char A='?';
ll n,a[N],cnt=0;
char c[N];
struct E{ll a;char c;}e[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=1;i<=n;i++){cin>>a[i]>>c[i];e[i].c=A;e[i].a=a[i];}
	for(ll i=2;i<=n;i++){
		if(c[i]==c[i-1]){
			e[i].c=c[i];
			e[i].a=a[i]+e[i-1].a;
			if(e[i-1].c==e[i].c) e[i-1].c=A;
		}else{
			if(i==2) e[1].c=c[1],e[1].a=a[1];
			e[i].c=c[i];
			e[i].a=a[i];
		}
	}
	ll l=1,r=n;
	while(l<r){
		if(e[l].c==A){l++;continue;}
		if(e[r].c==A){r--;continue;}
		if(e[l].c==e[r].c){
			ll len=max(e[l].a,e[r].a)-min(e[l].a,e[r].a);
			cnt+=len;l++,r--;continue;
		}else{
			if(e[l].a==e[r].a){cnt+=e[l].a;l++,r--;}
			else if(e[l].a>e[r].a){
				cnt+=e[r].a;
				e[l].a-=e[r].a;
				r--;continue;
			}else if(e[l].a<e[r].a){
				cnt+=e[l].a;
				e[r].a-=e[l].a;
				l++;continue;
			}
		}
	}
	cout<<cnt<<"\n";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*created by luve on 2026/10/31 9:40  60pts(?*/
