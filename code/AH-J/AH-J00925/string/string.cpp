#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n,cnt=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	    s.append(a[i],c[i]);
	}

	for(int i=0,j=s.size()-1;i!=j&&i<j;i++,j--){
		if(s[i]!=s[j]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
