#include<bits/stdc++.h>
using namespace std;
const int N=2*100000+5;
int n;
int a[N];
string b[N];
string s="";
int cnt=0,ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];

	}
	for(int i=0;i<n;i++){
        for(int j=0;j<a[i];j++){
            s+=b[i];
		}
	}
	int len=s.size();
	if(len%2==0){
        for(int i=0;i<len;i++){
            if(s[i]!=s[len-i]){
                s[len-i]=s[i];
            }
        }
	}
	else{
        for(int i=0;i<len-1;i++){
            if(s[i]==s[i+1]){
                continue;
            }
            if(s[i]!=s[len-i]){
                s[len-i]=s[i];
                cnt++;
            }
            if(s[(len+1)/2]==s[i]){
                cnt++;
            }
        }
	}
	cout<<cnt;
    return 0;
}
