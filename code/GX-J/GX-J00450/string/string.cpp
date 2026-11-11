#include<bits/stdc++.h>
using namespace std;
long long n;
string s;
long long sum=0;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
while(n--){
	long long a;
	char c;
	cin>>a>>c;
	for(long long i=0;i<a;i++){
		s+=c;
	}
}
long long left=s.size()-1;
for(int i=0;i<=left;i++){
	if(s[i]!=s[left]){
		sum++;
		}
	left--;
}
cout<<sum;
return 0;
}
