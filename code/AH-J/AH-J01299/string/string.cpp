#include<bits/stdc++.h>
using namespace std;

long long n,a,len;
char c;
string s;
int hw(string q){
	int cnt=0,j=0,len1=q.size();
	while(j<=len1/2){
		if(s[j]!=s[len1-1-j]){
			cnt++;
		}
		j++;
	}
	return cnt;
}
int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	len=s.size();
	cout<<hw(s);

    return 0;
}
