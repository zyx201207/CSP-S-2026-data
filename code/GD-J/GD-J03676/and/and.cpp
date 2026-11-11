#include <bits/stdc++.h>
using namespace std;
long long a,b,c,d,ar[1000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	freopen();
	cin>>a>>b;
	for (int i=1;i<=a;i++){
		cin>>ar[i];
	}
	sort(ar+1,ar+1+a);
	if (b==1){
		cout<<ar[a];
		return 0;
	}
	if (b==a){
		c=ar[1];
		for (int i=2;i<=a;i++){
			c=c&ar[i];
		}
		cout<<c;
		return 0;
	}
	if (b==a-1){
		c=ar[2];
		for (int i=3;i<=a;i++){
			c=c&ar[i];
		}
		cout<<c;
		return 0;
	}
	if (b<=20){
		for (int i=1;i<=a-b+1;i++){
			c=ar[i];
			for (int j=i;j<=b;j++){
				c=c&ar[j];
			}
			d=max(c,d);
		}
		cout<<d;
	}else{
		c=ar[a-b];
		for (int i=a-b;i<=a;i++){
			c=c&ar[i];
		}
		cout<<c;
	}
	
	
	
	return 0;
}
