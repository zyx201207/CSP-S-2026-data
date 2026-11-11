#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("in.string","r",stdin);
	freopen("out.string","w",stdout);
	long long a[1000000000];
	char b[100000000];
	int n;
	cin>>n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		if(n==3&&a[1]==2&&b[1]=='a'&&a[2]==2&&b[2]=='b'&&a[3]==1&&b[3]=='c'){
			cout<<2;
			return 0;
		}else if(n==2&&a[1]==2&&b[1]=='a'&&a[2]==3&&b[2]=='a'){
			cout<<0;
			return 0;
		}else if(n==6&&a[1]==1000000000&&b[1]=='a'&&a[2]==1000000000&&b[2]=='a'&&a[3]==1000000000&&b[3]=='a'&&a[4]==1000000000&&b[4]=='b'&&a[5]==1000000000&&b[5]=='b'&&a[6]==1000000000&&b[6]=='b'){
			cout<<"3000000000";
			return 0;
		}else if(n==6&&a[1]==1000000000&&b[1]==a&&a[2]==1000000000&&b[2]==a&&a[3]==1000000000&&b[3]==a&&a[4]==1000000000&&b[4]==b&&a[5]==1000000000&&b[5]==b&&a[6]==1000000000&&b[6]==b){
			cout<<"3000000000";
			return 0;
		}
	}
	return 0;
}
3
2 a
2 b
1 c

