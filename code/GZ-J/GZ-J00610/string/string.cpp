//GZ-J00610贵阳市第十八中学王梓钰
#include<bits/stdc++.h>
using namespace std;
string s;
int a[2000000005];
int l,x,m,n;
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>l;
	for(int i=0;i<l;i++){
		cin>>a[i]>>s[i];
	}
	for(int i=0;i-m<l/2;i++){
		if(s[i-m]!=s[l-i+n]){
			x=min(a[i-m],a[l-i+n]);
			sum+=x;
			a[i-m]-=x;
			a[n-i+n]-=x;
			if(a[i-m]) m++;
			if(a[n-i+n]) n++;
		}
	}
	cout<<sum;
	fclose(string.in);
	fclose(string.out);
	return 0;
}
