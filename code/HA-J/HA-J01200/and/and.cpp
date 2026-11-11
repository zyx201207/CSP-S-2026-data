#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2500000],k=1,num;
char s[2500000][60],ma[60];
string o,p;
int main(){
	freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		long long h=a[i],k=0;
		while(h){
			s[i][k]=h%2+'0';
			h=h/2;
			k++;
		}
	}
	sort(a+1,a+n+1);
	cout<<a[n-m+1];
	return 0;
}
