#include<bits/stdc++.h>
using namespace std;
int n;
char a[50000010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	int s,l=1,di=0,h=0,s1=0;
	if(n%2==1) h=1;
	for(int i=1;i<=n;i++){
		char c;
		int b;
		cin>>b>>c;
		for(int j=1;j<=b;j++){
			a[l]=c;
			l++;
		}
		s1+=b;
	}
	s=(s1+1)/2;
	if(s1%2==1) h=1;
	for(int i=s+1;i<=s1;i++){
		if(a[i]!=a[s-h]) di++;
		h++;
	}
	cout<<di;
	return 0;
}
