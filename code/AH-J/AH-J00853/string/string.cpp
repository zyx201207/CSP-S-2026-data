#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
typedef long long ll;
int n,a,cnt;
char x;
string s;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
		cin>>a>>x;
		for(int j=1;j<=a;j++){
			s+=x;
		}
	}
	int l=0,r=s.size()-1;
	while(l<=r){
	   if(s[l]!=s[r]){
		   cnt++;
	   }
	   l++,r--;
   }
   cout<<cnt;
    return 0;
}
