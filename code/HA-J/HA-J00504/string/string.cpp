#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],z;
char c[200005];
string s;
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
			z++;
		}
	}
	int i=0;
	z--;
	while(i<=z){
		if(s[i]!=s[z]){
			sum++;
		}
		i++;
		z--;
	}
	cout<<sum;
	return 0;
}
