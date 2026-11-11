#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char a[200011];
	long long b[200011];
	long long n,h=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i]>>a[i];
		h+=b[i]/2+b[i]%2;
	}
	cout<<1<<endl;
	long long l=1,lv=1,rv=n,x=0,c=h/2;
	long long r=b[rv];
	while(c--){
		if(l>b[lv])lv++,l=1;
		if(r<=0)rv--,r=b[rv];
		if(a[lv]!=a[rv])x++;
		l++,r--;
	}
	cout<<x;
	return 0;
}
