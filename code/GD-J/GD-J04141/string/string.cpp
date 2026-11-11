#include<bits/stdc++.h>
using namespace std;
long long n,m1=0,cnt=0;
string m;
bool hwc(int x){
	if(m[x]!=m[m1-x-1])return 1;
	return 0;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char a;
		cin>>x>>a;
		for(int j=1;j<=x;j++)m+=a;
		m1+=x;
	}
	for(int i=0;i<=m1/2;i++)if(hwc(i))cnt++;
//	cout<<cnt<<" "<<m<<" "<<m1;
	return 0;
}
