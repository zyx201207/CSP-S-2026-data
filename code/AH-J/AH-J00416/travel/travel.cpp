#include<bits/stdc++.h>
#define int long long
using namespace std;
string a,b;
string s,t;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>b>>t;
	int a1=(a[0]-'0')*10+(a[1]-'0');
	int b1=(b[0]-'0')*10+(b[1]-'0');
	if(a1==b1){
		cout<<1;
		int s1=(s[0]-'0')*10+(s[1]-'0');
		int t1=(t[0]-'0')*10+(t[1]-'0');
		if(s1==t1){
			cout<<1;
			char s2=s[2],s3=t[2];
			if(s2=='A'){
				if(s3=='B'||s3=='C'){
					cout<<1;
					if(s3=='B')cout<<1;
					else cout<<0;
				}
				else cout<<0<<0;
			}else if(s2=='B'){
				if(s3=='A'||s3=='C'){
					cout<<1;
					if(s3=='A'||s3=='C')cout<<1;
					else cout<<0;
				}
				else cout<<0<<0;
			}else if(s2=='C'){
				if(s3=='A'||s3=='B'){
					cout<<1;
					if(s3=='B')cout<<1;
					else cout<<0;
				}
				else cout<<0<<0;
			}else if(s2=='D'){
				if(s3=='F'){
					cout<<1;
					if(s3=='F')cout<<1;
					else cout<<0;
				}
				else cout<<0<<0;
			}else if(s2=='F'){
				if(s3=='D'){
					cout<<1;
					if(s3=='D')cout<<1;
					else cout<<0;
				}
				else cout<<0<<0;
			}
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	fclose(stdin);
	fclose(stdout);
}
