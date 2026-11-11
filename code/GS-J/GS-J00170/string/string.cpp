#include<bits/stdc++.h>
using namespace std;
int n;
char a[200005];
int m[200005];
string s;
long long tj=0,bj,sum=0;
int main(){
	freopen("string.in","r",stdin); 
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i]>>a[i];
		tj+=m[i];
		for(int j=1;j<=m[i];j++){
			s+=a[i];
		}
	}
	bj=tj-1;
	for(int i=0;i<tj/2;i++){
		if(s[i]!=s[bj])sum++;
		bj--;
	}
	cout<<sum;
	return 0;
}

