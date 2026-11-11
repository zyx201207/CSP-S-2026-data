#include<bits/stdc++.h>
using namespace std;
string s;
long long a;
char c;
long long  d;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
   	int n;
	cin>>n;
   	while(n--){
   		cin>>a>>c;
		for(int i=0;i<a;i++){
			s=s+c;
		}
	}
	long long ss=s.size();
	int p=0,q=ss-1;
	for(int i=0;i<ss;i++){
		if(p==q||q-p==1) break;
		if(s[p]!=s[q]) d++;
		p++;
		q--;
	}
	cout<<d;
}

