#include<bits/stdc++.h>
using namespace std;
long long a[6767];
char s;
long long x,n,sum,ma;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>s;
		a[s]+=x;
	}
 	for(int i=97;i<=167;i++){
 		if(a[i]!=0){
 			sum++;
 			ma=max(ma,a[i]);
		 }
	}
	if(sum==1) cout<<0;
	else cout<<ma;
	return 0;
}