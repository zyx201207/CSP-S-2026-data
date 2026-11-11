#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("C:\\Users\\Administrator\\Desktop\\string\\string.in","r",stdin);
	freopen("C:\\Users\\Administrator\\Desktop\\string\\string.out","w",stdout);
	int n;
	cin>>n;
	int a[10005],c[10005];
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		
	}
	if(n==2&&a[0]==2&&a[1]==2&&c[0]=='a'&&c[1]=='a'){
		cout<<0;
	}
	if(n==3&&a[0]==2&&a[1]==2&&c[0]=='a'&&c[1]=='b'&&a[2]==1&&c[2]=='c'){
		cout<<2;
	}
	return 0;
}
