//GZ-J00468 遵义市第十二中学 周泽恩 
#include<bits/stdc++.h>

using namespace std;
long long n;
long long c[2000005];
char a[2000005];
char s[200000005];
long long l=0,cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i]>>a[i];
		
	}
	for(int i=1;i<=n;i++){
		while(c[i]--){
			s[l++]=a[i];
		} 
	}
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-1-i])cnt++;
	}
	cout<<cnt;
	fclose(stdin);
	fclose(stdout);
} 
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
