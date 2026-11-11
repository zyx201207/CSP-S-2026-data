#include<iostream>
using namespace std;
long long n,m,j,cnt,ans;
char a;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>m>>a;
		ans+=m;
		int l=ans-m,r=ans;
		while(l<=r){
			s[l]=a,s[r]=a;
			l++,r--;
		}
	}
	long long l=0,r=ans-1;
	while(l<=r){
		if(s[l]!=s[r]) cnt++;
		l++,r--;
	}
	cout<<cnt;
	return 0;
} 
