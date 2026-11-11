#include<bits/stdc++.h>
using namespace std;
struct st{
	long long a;
	char b;
} a[200005];
int b[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	cin>>a[1].a>>a[1].b;
	char now=a[1].b;
	int st=1;
	for(int i=2;i<=n;i++){
		int na;
		char nb;
		cin>>na>>nb;
		if(nb==now)
			a[st].a+=na;
		else{
			a[++st].a=na;
			a[st].b=nb;
			now=nb;
		}
	}
	if(st==1){
		cout<<0;
		return 0;
	}
	int tp=1;
	for(int i=1;i<=st;i++){
		int nb=a[i].b-'a'+1;
		b[tp]+=nb;
		tp+=a[i].a;
		b[tp]-=nb;
	}
	for(int i=1;i<tp;i++)
		b[i]+=b[i-1];
	long long as=0;
	for(int i=1,j=tp-1;i<j;i++,j--){
		if(b[j]!=b[i])
			as++;
	}
	cout<<as; 
	return 0;
}
