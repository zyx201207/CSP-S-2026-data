#include<bits/stdc++.h>
using namespace std;
string s;
int a[100000000100];
int b[100000000100];
int many;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	int sum;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s;
		a[i]=s[i]-'0';
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		sum=1;
		many=m;
		for(int j=i-1;j>=1;j--){
			many-=a[i]-a[j];
			if(many>=0) sum++;
		}
		b[i]=sum;
	}
	sort(b+1,b+n+1);
	cout<<b[n];
	return 0;
}
