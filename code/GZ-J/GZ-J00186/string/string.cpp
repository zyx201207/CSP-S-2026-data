//GZ-J00186 六盘水市第三中学 柴大寓 
#include <bits/stdc++.h>
using namespace std;
long long n;
vector<char> s;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		long long a; char c;
		cin>>a>>c;
		for(long long i=0;i<a;i++) s.push_back(c);
	}
	long long l=s.size(),sum=0;
	for(long long i=0;i<l/2;i++){
		if(s[i]!=s[l-1-i]) sum++;
	}cout<<sum;
	return 0;
}
