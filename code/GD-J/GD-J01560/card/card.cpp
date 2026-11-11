#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5000005],l,o[5000005];
string s;
char ch;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s="";
		for(int j=i;j<=n;j++){
			if(s.find(char(a[j]+'0'))<=(s.size())){
				s.erase(s.find(char(a[j]+'0')),(s.size()-s.find(char(a[j]+'0'))));
				s+=char(a[j]+'0');
				continue;
			}
			s+=char(a[j]+'0');
		}
		for(int j=1;j<=m;j++){
			if(s.find(char(j+'0'))<=s.size()){
				o[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<o[i]<<" ";
	}
	return 0;
}

