#include <bits/stdc++.h>
using namespace std;
long long int n,s=0,m;
vector <char> a;
char w;
int main(){
	freopen ("string.in","r",stdin);
	freopen ("string.out","w",stdout);
	cin>>n;
	for (int p=1;p<=n;p++){
		cin>>m>>w;
		for (int i=0;i<m;i++) a.push_back(w);
	}
	
	int l=0,r=a.size()-1;
	while (l<r){
		if (a[l]!=a[r]){
			s++;
		}
		l++;
		r--;
	}
	cout<<s;
	return 0;
}
