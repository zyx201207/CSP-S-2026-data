#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
string s;
char c;
int a[N],n;
long long ans=0,m;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
		for(int j=m;j<a[i]+m;j++){
			s[j]+=c;
		}
		m+=a[i];
	}
	int len=s.size();
	for(int i=0,j=m-1;i<=j;i++,j--){
		if(s[i]==s[j])continue;
		else{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
/*
3
2 a
2 b
1 c

6
100 a
100 a
100 a
100 b
100 b
100 b
*/
