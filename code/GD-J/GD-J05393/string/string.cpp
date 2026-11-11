#include<bits/stdc++.h>
using namespace std;
const int inf=2e5+7;
int n,m,i,j,k,l,h,cnt;
struct ab{
	int ni;
	char ai;
}a[inf];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i].ni>>a[i].ai;
		for(j=1;j<=a[i].ni;j++){
			s+=a[i].ai;
		}
	}
	//cout<<s;
	l=s.size()-1;
	for(i=0;i<=l/2;i++){
		if(s[i]!=s[l-i]) cnt++;
	}
	cout<<cnt;
	return 0;
}

