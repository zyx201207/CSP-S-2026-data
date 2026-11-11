#include<bits/stdc++.h>
using namespace std;
long long n,a[110000],cnt,l;
string c,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
		l+=a[i];
		s+=c[i];
	}
	for(int i=1;i<=n;i++){
		if(c[i]==c[i+1]){
			flag++;
		}
	}
	if(flag==l){
		cout<<0;
		return 0;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		long long x=a[1];
		long long y=a[2];
		cout<<min(x,y);
		return 0;
	}
	return 0;
}
