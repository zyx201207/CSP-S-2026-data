#include<iostream>
#include<cstdio> 
using namespace std;
string s;
long long n,a,cnt=0;
char le; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>le;
		while(a--){
			s+=le;
		}
	}long long l=s.size(),ans=(l%2==0)?(l/2):(l/2+1);
	for(int i=0;i<ans;i++){
		if(s[i]!=s[l-1-i]){
			cnt++;
		}
	}cout<<cnt;
	return 0;
}
