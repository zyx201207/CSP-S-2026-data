#include<bits/stdc++.h>
using namespace std;
long long n;
string s;
long long cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>n;
    if(n==1){
		cout<<0;
		return 0;
	}
    for(int i=1;i<=n;i++){
		long long a;
		string b;
		cin>>a>>b;
		cnt+=a;
		for(int j=1;j<=a;j++){
			s+=b;
		}
	}
	long long sum=0;
	for(int i=1;i<=cnt/2;i++){
		if(s[i]==s[cnt/2-i]){
			sum++;
		}
	}
	cout<<min(sum+1,cnt/2-sum+1);
	return 0;
}
