#include<bits/stdc++.h>
using namespace std;
long long n,a[10000005],num;
char c[10000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	char s[1000005];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s[num]=c[i];
			num++;
		}
	}
	num--;
	int u=num/2+1;
	int y=0;
	for(int i=0;i<u;i++){
		if(s[i]!=s[num-i]){
			y++;
		}
	}
	cout<<y;
	return 0;
}
