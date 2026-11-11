#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string.in","r",stdin)
	//freopen("string.out","w",stdout)
	long long n,r,b=0,c=0,e=0;
	char l,a[2000010];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>r>>l;
		for(int j=i;j<i+r;j++){
			b++;
			a[b]=l;
		}
		c+=r;
	}
	int d=c/2;
	for(int i=1;i<=d;i++){
		if(a[i]!=a[c-i+1]){
			e++;
		}
	}
	cout<<e;
	return 0;
}
