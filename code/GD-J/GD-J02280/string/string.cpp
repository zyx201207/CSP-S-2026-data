#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5;
struct lef{
	ll num;
	char c;
}l[N+1],r[N+1];
ll a[N+1];
char s[N+1];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	ll sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		sum+=a[i];
	}
	bool flag=0;
	if(sum%2==1) flag=1;
	sum/=2;
	ll nu=0;
	int id=1;
	int tot=0,top=0;
	while(nu+a[id]<=sum){
		l[++tot].num=a[id];
		l[tot].c=s[id];
		nu+=a[id];
		id++;
	}
	if(nu<sum){
		l[++tot].num=sum-nu;
		l[tot].c=s[id];
		a[id]-=(sum-nu); 
	}
	if(flag==1){
		a[id]--;
		if(a[id]==0) id++;
	}
	for(id;id<=n;id++){
		r[++top].num=a[id];
		r[top].c=s[id];
	}
	int le=1,ri=top;
	ll ans=0;
	while(le<=tot&&ri>=1){
		ll k=min(l[le].num,r[ri].num);
		if(l[le].c!=r[ri].c){
			ans+=k;
		}
		l[le].num-=k;
		r[ri].num-=k;
		if(l[le].num==0) le++;
		if(r[ri].num==0) ri--;
	}
	cout<<ans;
	return 0;
} 
