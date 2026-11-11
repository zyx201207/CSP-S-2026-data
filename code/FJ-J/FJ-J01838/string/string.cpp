#include<bits/stdc++.h>
using namespace std;
string a;
long long num,cnt,n; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		char b;
		long long l;
		scanf("%d %s",&l,&b);
		for(int j = 1;j<=l;j++){
			num++;
			a[num]=b;
		}
	}
	for(int i = 1;i<=num/2;i++){
		if(a[i]!=a[num-i+1])cnt++;
	}
	cout<<cnt;
	return 0;
}
