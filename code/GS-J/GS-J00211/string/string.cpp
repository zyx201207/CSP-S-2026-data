#include<bits/stdc++.h>
using namespace std;
long long n,cc;
long long a;
string s;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
        cin>>a>>c;
        for(int j=0;j<a;j++){
            s+=c;
        }
	}
	int l=s.size();
	//cout<<s;
	for(int i=0;i<l;i++){
        if(s[i]!=s[l-1-i]){
            cc++;
            s[i]=s[l-1-i];
            //cout<<i;
        }
	}
	cout<<cc;
	return 0;
}
