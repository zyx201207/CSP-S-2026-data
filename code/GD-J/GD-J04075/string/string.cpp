#include<bits/stdc++.h>
using namespace std;
const long long N=10000010;
long long n;
string str;
long long num;
struct Node{
	long long second;
	char first;
}mp[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long a;
		char op;
		cin>>a>>op;
		mp[i].second=a;
		mp[i].first=op;
	}
	for(long long i=1,j=n;i<=j;){
		if(mp[i].first!=mp[j].first){
			long long a=mp[i].second,b=mp[j].second;
			if(a>b){
				mp[i].second-=b;
				j--;
				num+=b;
			}else if(a==b){
				i++,j--;
				num+=b;
			}else{
				mp[j].second-=a;
				i++;
				num+=a;
			}
		}else{
			long long a=mp[i].second,b=mp[j].second;
			if(a>b){
				mp[i].second-=b;
				j--;
			}else if(a==b){
				i++,j--;
			}else{
				mp[j].second-=a;
				i++;
			}
		}
	}
	cout<<num;
	return 0;
}


