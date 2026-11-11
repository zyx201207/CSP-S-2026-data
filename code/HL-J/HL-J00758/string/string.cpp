#include<bits/stdc++.h>
using namespace std;
long long n,c=0,a[200005],l,r,e=0;
string b[200005],q="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		c+=a[i];
		for(int j=1;j<=a[i];j++){
			q+=b[i];
		}
	}
	l=0,r=c-1;
	for(int i=1;i<=c/2;i++){
		if(q[l]!=q[r]){
			e++;
			i++;
			r--;
		}
	}
	cout<<e;
	return 0;
}