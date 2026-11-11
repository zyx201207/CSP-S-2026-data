#include <bits/stdc++.h>
using namespace std;
long long n,sum=0;
string s="";
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
        cin>>a>>c;
        for(int j=1;j<=a;j++){
        	s+=c;
		}
        
    }
    int l=0,r=s.size()-1;
    while(l<r){
    	if(s[l]!=s[r]){
    		sum++;
		}
		l++;
		r--;
	}
	cout<<sum;
	return 0;
} 
/*
3
2 a
2 b
1 c
aaaaa
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
