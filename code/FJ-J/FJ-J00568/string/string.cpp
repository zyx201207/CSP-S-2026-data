#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	char c[100000];
	int a[100000];
	string l;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		while(a[i]--){
			l+=c[i];
		}
	}
	int cnt=0;
	for(int r=0,w=l.size()-1;r<l.size();r++,w--){
		if(l[r]!=l[w]){
			cnt++;
			l[w]=l[r];
		}
	}
	cout<<cnt;
	return 0;
}
