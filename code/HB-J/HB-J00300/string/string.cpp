#include<bits/stdc++.h>
using namespace std;
struct T{
	long long a;
	char b;
};
T str[200009];
string s;
long long cnt=0,n,mx=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>str[i].a>>str[i].b;
		mx+=str[i].a;
		if(mx<=1e8){
			for(int j=1;j<=str[i].a;j++){
				s+=str[i].b;
			}
		}
	}
	if(mx<=1e8){
		long long l=0,r=s.size()-1;
		while(l<=r){
			if(s[l]!=s[r]){
				s[l]=s[r];
				cnt++;
			}
			l++;
			r--;
		}
		cout<<cnt;
	}
	else{
		long long l=1,r=n;
		while(l<=r){
			if(str[l].b!=str[r].b){
				cnt+=str[l].a;
				//x=abs(str[l].a-str[r].a);
			}
			l++;
			r--;
		}
		cout<<cnt;
	}
	return 0;
}
