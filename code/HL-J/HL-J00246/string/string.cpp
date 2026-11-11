#include<bits/stdc++.h>
using namespace std;
int n;
string s;
bool huiwen(string x,long long l){
	for(int i=0;i<l;i++){
		if(x[i]!=x[l-i-1])return 0;
	}
	return 1;
}
long long chuli(string x,long long l){
	long long cnt=0;
	for(int i=0;i<l/2;i++){
		if(x[i]!=x[l-i-1])cnt++;
	}
	return cnt;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    long long l=0;
    for(int i=1;i<=n;i++){
        long long a;
        char c;
        cin>>a>>c;
        for(int j=1;j<=a;j++){
            s+=c;
        }
        l+=a;
    }
	if(huiwen(s,l))cout<<0<<endl;
    else{
        cout<<chuli(s,l)<<endl;
	}
    return 0;
}
