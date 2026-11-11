#include<iostream>
#define ll long long
#define endl "\n"
using namespace std;
int n,a[200010],bj=0;
ll l=0,sum=0;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	if (l%2==0) bj=1;
	l/=2;
	ll i=0,noi=1,noj=n;
	while (i<l){
		if (c[noi]==c[noj]){
			if (a[noi]==a[noj]){
				if (a[noi]+i>l) i=l;
				else i+=a[noi];
				noi++,noj--;
			}else if(a[noi]<a[noj]){
				if (a[noi]+i>l) i=l;
				else i+=a[noi];
				a[noj]-=a[noi];
				noi++;
			}else{
				if (a[noj]+i>l) i=l;
				else i+=a[noj];
				a[noi]-=a[noj];
				noj--;
			}
		}else{
			if (a[noi]==a[noj]){
				if (a[noi]+i>l) i=l;
				else i+=a[noi];
				sum+=a[noi];
				noi++,noj--;
			}else if(a[noi]<a[noj]){
				if (a[noi]+i>l) i=l;
				else i+=a[noi];
				a[noj]-=a[noi];
				sum+=a[noi];
				noi++;
			}else{
				if (a[noj]+i>l) i=l;
				else i+=a[noj];
				a[noi]-=a[noj];
				sum+=a[noj];
				noj--;
			}
		}
	}
	cout<<sum;
	return 0;
}
/*
math
3
2 a
2 b
1 c

aa b bc
compare aa and bc lol
kk we need double *
for exp

5
3 a
4 b
3 c
1 d
2 a

aaabbb b aacccd
aaa bbb|ccc d aa
sum:4

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
yay gg
*/
