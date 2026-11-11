#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	long long n,l=0,cnt=0;
	cin>>n;
	long long a[n+5];
	char c[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	int x=1,y=n;
	for(int i=1;i<=l/2;i++){
		a[x]--;
		a[y]--;
		if(c[x]!=c[y]){
			cnt++;
		}
		if(a[x]==0)x++;
		if(a[y]==0)y--;
	}
	cout<<cnt<<endl;
	return 0;
}
