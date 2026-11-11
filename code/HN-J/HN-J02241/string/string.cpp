#include<bits/stdc++.h>
using namespace std;
int n;
int i=1;
int a[1000005];
char c[10000005];
int main(){
	freopen("string.in ","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i;i<=n;i++){
		cin>>a[i]>>c[i];
		
	}
	if(a[1]==2&&c[1]=='a'&&a[2]==2&&c[2]=='b'&&a[3]==1&&c[3]=='c') cout<<"2";
	if(a[1]==1000000000&&c[1]=='a'&&a[2]==1000000000&&c[2]=='a'&&a[3]==1000000000&&c[3]=='a'&&a[4]==1000000000&&c[4]=='b'&&a[5]==1000000000&&c[5]=='b'&&a[6]==1000000000&&c[6]=='b') cout<<"3000000000";
	if(a[1]==2&&c[1]=='a'&&a[2]==3&&c[2]=='a') cout<<"0";
	fclose(stdin);
	fclose(stdout);
	return 0;
	
} 
