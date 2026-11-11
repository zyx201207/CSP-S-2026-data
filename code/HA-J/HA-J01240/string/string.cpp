#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	int n;
	long long cnt=0,sum=0;
	cin>>n;
	long long a[n+1];
	char b[n+1];
	string s;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cnt+=a[i];
		cin>>b[i];
		for(int j=0;j<a[i];j++){
			s+=b[i];
		}
	}
	if(cnt%2==0){
		cnt=cnt/2-1;
	}
	if(cnt%2==1){
		cnt=cnt/2;
	}
	for(int i=cnt+1;i<s.size();i++){
		if(s[i]!=s[s.size()-1-i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
