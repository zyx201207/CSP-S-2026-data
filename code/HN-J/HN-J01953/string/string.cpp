#include<bits/stdc++.h>
using namespace std;
long long n,w=0,k=0,rt=0;
char s[10000005];
long long a[200005];
char c[200005];
bool hui(){
	for(int i=1;i<=w/2+1;i++){
		if(s[i]!=s[w-i])k++;
	}
	if(k!=0)return false;
	return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		rt+=a[i];
		cin>>c[i];
		//cout<<i<<'\n';
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s[w]=c[i];
			//cout<<i<<'\n';
			//cout<<s.size()<<'\n';
			w++;
		}
	}
	w-=1;
	if(hui()){
		cout<<0;
		return 0;
	}
	cout<<k;
	return 0;
} 

