#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10;
int n;
string s;
long long x[N],ans;
bool flag=true,flagt=true;
char y[N];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		if(i>1 && y[i]!=y[i-1]){
			flag=false;
		}
		if(i>1 && x[i]!=x[i-1]){
			flagt=false;
		}
	}
	if(flag){
		cout<<0;
		return 0;
	}
	if(flagt){
		for(int i=1;i<=n/2;i++){
			if(y[i]!=y[n-i+1]) ans+=x[i];
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=x[i];j++){
			s+=y[i];
		}
	}
	int len=s.size();
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
