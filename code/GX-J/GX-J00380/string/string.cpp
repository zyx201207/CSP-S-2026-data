#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s1,d;
	long long n,a,z=0,m=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>d;
		z+=a;
		for(int j=0;j<a;j++){
			s1+=d;
		}
	}
	z--;
	for(int i=0;i<z/2;i++){
		if(s1[i]!=s1[z-i]&&i!=z-i)m++;
		}
	cout<<m;
	return 0;
}
