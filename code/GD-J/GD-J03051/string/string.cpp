#include<bits/stdc++.h>
using namespace std;
string s;
char d;
long long sum=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,t;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t>>d;
		for(int i=1;i<=t;i++)
		s+=d;
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-(i+1)]){
		sum++;
		}
	}
	cout<<sum;
	return 0;
}
//time:O(<s.size()*k)(k is max of all t)
//space:O(<s.size()*k)(k is max of all t)
