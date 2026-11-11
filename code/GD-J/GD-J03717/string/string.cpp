#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn=2*1e5+5;
long long a[maxn];
char c[maxn];
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin>>n;
	long long  f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	string s;
	int j=1;
	while(n--){
		for(int i=1;i<=a[j];i++){
			s+=c[j];
		}
		j++;
	}
	for(int i=0;i<(s.size()+1)/2;i++){
		if(s[i]!=s[j]){
			f++;
		}
		j--;
	}
	cout<<f;
	return 0;
}
