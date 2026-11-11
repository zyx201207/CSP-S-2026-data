#include <bits/stdc++.h>
using namespace std;

int l[10005];
int cmp(int m,int n){
	return m>n;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a,b;
	cin>>a>>b;
	
	for(int i=0;i<a;i++){
		cin>>l[i];
	}
	sort(l,l+a,cmp);
	long long cnt=l[0];
	for(int j=1;j<b;j++){
		cnt=(cnt&l[j]);
	}
	cout<<cnt;
	return 0;
} 
