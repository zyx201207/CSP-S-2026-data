#include <bits/stdc++.h>
using namespace std;
struct st{
	long long a;
	char c;
}s[200001];
char w[200001];
long long n;
string x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
		for(long long i=1;i<=s[i].a;i++){
			x+=s[i].c;
		}
		w[s[i].c]=s[i].a;
		
	}
	bool f=1;
	for(long long i=0;i<x.size()-1;i++){
		if(x[i]!=x[i+1]){
			f=0;
		}
	}
	if(f==1){
		cout<<"0";
		return 0;
	}
	bool e=1;
	for(long long i=1;i<n;i++){
		if(w[s[i].c]!=w[s[i+1].c]){
			e=0;
		}
	}
	if(e==1){
		cout<<min(s[1].a,w[s[1].c]);
		return 0;
	}
	long long cnt=0,sum=(x.size()-1)/2;
	for(long long i=0;i<=sum;i++){
		for(long long j=sum;j>=0;j--){
			if(x[i]!=x[j]){
				cnt++;
		}
	}
	cout<<cnt+1;
	return 0;
}
