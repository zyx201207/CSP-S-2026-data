#include<bits/stdc++.h>
using namespace std;
const int ma=200005;
int a[ma],d[ma];
char c[ma];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,t=0,l=1,r=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		r+=a[i];
		d[i]=d[i-1]+a[i];
	}
	long long z=r;
	for(int i=1;i<=z/2;i++){
		char lt,rt;
		for(int j=1;j<=n;j++){
			if(l>d[j-1] && l<=d[j]){
				lt=c[j];
			}
		}
		for(int j=n;j>=1;j--){
			if(r>d[j-1] && r<=d[j]){
				rt=c[j];
			}
		}
		if(lt!=rt){
			t++;
		}
		l++;
		r--;
	}
	cout<<t;
	return 0;
} 
