#include <bits/stdc++.h>
using namespace std;
int n,a[200005][5],c,j;
long long s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.ont","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		j=1;
		cin>>a[j][1]>>c;
		s+=a[j][1];
		if(c-'a'+1==a[j-1][2]){
			a[j-1][1]+=a[j][1];
			j--;
		}
		a[j][2]=c-'a'+1;
		j++;
	}
	if(j=2){
		cout<<0;
		return 0;
	}
	if(j=3){
		cout<<max(a[1][1]-a[2][1],a[2][1]-a[1][1]);
		return 0;
	}
	cout<<s/2;
	return 0;
}