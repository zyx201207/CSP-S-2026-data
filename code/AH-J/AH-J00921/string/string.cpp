#include<bits/stdc++.h>
using namespace std;
int n;
long long hw(string s){
	long long sum=0;
	int b=s.length();
	for(int i=0;i<=b/2;i++){
		if(s[i]!=s[n-i-1]){
			sum++;
		}
	}
	return sum;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
    }
    cout<<hw(s);
    return 0;
}
