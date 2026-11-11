#include<bits/stdc++.h>
using namespace std;
struct numb{
	char ch;
	long long x;
}a[200010];
char b[100000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m,flag=0,len=1,num=0;
	cin>> n;
	for(int i=1; i<=n; i++){
		cin>> a[i].x >> a[i].ch;
		for(int j=1; j<=a[i].x; j++){
			b[len]=a[i].ch;
			len++;
		}
	}
	for(int i=1; i<=len/2; i++){
		if(b[i]!=b[len-i+1]){
			num++;
		}
	}
	cout<< num;
	return 0;
}
