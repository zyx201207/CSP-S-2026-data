#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1000000;
ll n,m,a[N];

ll read(){
	ll s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*w;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	ll sum=0;
	for(ll i=1;i<=n;i++){
		a[i]=read();
		sum+=a[i];
	}
	sort(a+1,a+n+1);
	ll t=sum/n,loc;
	for(ll i=1;i<=n;i++){
		if(a[i]>=t){
			loc=i;
			break;
		}
	}
	t=a[loc];
	ll sec=0;
	for(ll i=loc;i<=n;i++){
		if(a[i]==t){
			sec++;
		}
	}
	ll fis=0;
	for(ll i=loc-1;i>=1;i--){
		if(m-(t-a[i])>=0){
			m=m-(t-a[i]);
			fis++;
		}
	}
	cout<<fis+sec<<'\n';
	return 0;
}
