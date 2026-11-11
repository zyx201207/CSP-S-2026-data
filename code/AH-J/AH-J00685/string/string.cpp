#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=2e5+10;
struct node{char c;ll num;}a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll tot,n=0;
	cin>>tot;
	for(int i=1;i<=tot;i++){
		char s;ll m;
		scanf("%lld",&m);
		cin>>s;
		if(n==0||s!=a[n].c){
			a[++n].c=s;
			a[n].num=m;
		}else a[n].num+=m;
	}
	ll r=n,sum=0;
	for(int i=1;i<r;i++){
		if(a[i].c==a[r].c){
			if(a[i].num==a[r].num) r--;
			else if(a[i].num<a[r].num) a[r].num-=a[i].num;
			else{
				a[i].num-=a[r].num;
				r--;
				i--;
			}
			continue;
		}
		if(a[i].num==a[r].num){
			sum+=a[i].num;
			r--;
		}else if(a[i].num<a[r].num){
			sum+=a[i].num;
			a[r].num-=a[i].num;
		}else{
			sum+=a[r].num;
			a[i].num-=a[r].num;
			r--;
			i--;
		}
	}
	cout<<sum;
	return 0;
}
