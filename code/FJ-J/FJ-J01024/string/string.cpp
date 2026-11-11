#include <bits/stdc++.h>
using namespace std;	
int main(){
	long long m[1000001],num,sum,mid;string s;
	int n;char a[1000001];cin>>n;
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>m[i];cin>>a[i];
		sum+=m[i];
		for(int j=1;j<=m[i];j++){
			s+=a[i];
		}
	}
	mid=sum/2;
	for(int i=1;i<=mid;i++){
		if(s[i]==s[n-i]){
			num++;
		}
	}
	cout<<num;
	return 0;
}
