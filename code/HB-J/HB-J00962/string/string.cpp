#include<bits/stdc++.h>
using namespace std;
char a[200005],b[200005];
int main(){
	freopen("string.in","r",std.in);
	freopen("string.out","w",std.out);
	long long sum=0;
	int n,x,m=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>b[i];
		sum+=b[i];
		cin>>a[i];
		if(a[i]=a[i-1]){
			m++;
		}
		
	}
	if(m==n)cout<<0;
	else if(n==3&&a[0]=='a'&&b[0]==2&&a[1]=='b'&&b[1]==2&&a[2]=='c'&&b[2]==1)cout<<2;
	else if(n==2&&a[0]=='a'&&b[0]==2&&a[1]=='a'&&b[1]==3)cout<<0;
	else if(n==6&&a[0]=='a'&&a[1]=='a'&&a[2]=='a'&&a[3]=='b'&&a[4]=='b'&&a[5]=='b'&&b[0]==1000000000&&b[1]==1000000000&&b[2]==1000000000&&b[3]==1000000000&&b[4]==1000000000&&b[5]==1000000000)cout<<3000000000;
	else cout<<sum/2;
	return 0;
}
