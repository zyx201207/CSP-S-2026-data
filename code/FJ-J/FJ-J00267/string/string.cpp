#include<bits/stdc++.h>
using namespace std;
int n,a,c=1,e;
char b[100000000],d;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>d;
		for(int i=c;i<=c+a;i++){
			b[i]=d;
		}
		c+=a;
	}
	for(int i=1;i<=(c-1)/2;i++){
		if(b[i]!=b[c-i]){
			e++;
		}
	}
	cout<<e;
	return 0;
}
