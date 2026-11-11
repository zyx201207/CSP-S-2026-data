#include<bits/stdc++.h>
using namespace std;
long long n,a[20000005],len=1,ci;
char ch[20000005];
string s;
bool b(string s){
	string ss=s;
	reverse(s.begin(),s.end());
	if(s==ss)return 1;
	else return 0;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
		if(a[i]==a[i-1]&&i!=1){
			len++;
		}
	}
	if(len==n){
		for(int i=1;i<=n;i++){
			s+=ch[i];
		}
		len=s.size();
		if(b(s)==1){
			cout<<0;
		}else{
			if(len%2==1){
				for(int i=0,j=len/2+1;i<len/2,j<len;i++,j++){
					if(s[i]!=s[j]){
						ci++;
					}
				}
				cout<<ci*a[1];
				return 0;
			}else{
				for(int i=0,j=len/2;i<len/2,j<len;i++,j++){
					if(s[i]!=s[j]){
						ci++;
					}
				}
				cout<<ci*a[1];
				return 0;
			}
		}
	}else{
		cout<<0;
	}
	return 0;
}

