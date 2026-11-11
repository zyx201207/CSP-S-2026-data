#include<bits/stdc++.h>
using namespace std;
long long n,k,m,h;
char l;
string s;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>k>>l;
		m+=k;
		for(long long j=0;j<k;j++){
			s+=l;
		}
	}
		long long r=0,l=m-1;
		for(long long i=1;i<=m/2;i++){
			if(s[r]!=s[l]){
				h++;
			}	
			r++;
			l--;
		}	
		cout<<h;
		return 0;
}
