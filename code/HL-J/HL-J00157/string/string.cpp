#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,cnt=0;
    cin>>n;
    string s;
    for(int i =1;i<=n;i++){
    	int a;
    	char c;
    	cin>>a;
    	cin>>c;
    	for(int j=1;j<=a;j++){
    		s+=c;
		}
	}
	long long lens=s.size();
	for(int i=0;i<lens/2;i++){
		if(s[i]!=s[lens-i-1]){
			cnt++;
		}
	}
	cout<<cnt;
    return 0;
}
