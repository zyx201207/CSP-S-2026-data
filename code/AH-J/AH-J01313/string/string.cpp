#include <bits/stdc++.h>
using namespace std;
const int d=1e7;
string s[d];
char s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m,k=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>s1;
		for(int j=0;j<m;j++){
			s[k++]=s1;
		}
	}
	int l=0,r=k,cnt=0;
	int ans=k/2;
	while(l<ans){
		for(int i=r-1;i>=ans;i--){
			if(s[i]!=s[l]){
				cnt++;
			}
			l++;	
		}
		
	}
	cout<<cnt;
	return 0;
}
