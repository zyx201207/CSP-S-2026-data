#include <bits/stdc++.h>
using namespace std;
char s[100010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,j=1,sum=0;
	char b;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a>>b;
		for (int x=j;x-j<=a;x++){
			s[x]=b;
		}
		j+=a;
	}
	
	int l=1,r=j;
	for (int i=0;i<=j/2;i++){
		if (s[l]!=s[r]){
			sum++;
		}
		l++;
		r--;
	}
	cout <<sum;
	return 0;
}
