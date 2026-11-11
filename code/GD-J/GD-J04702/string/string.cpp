#include<bits/stdc++.h>
using namespace std;
int a[10005];
string s[10005];
string m[10005];
string b[10005];
int cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin >> a[i] >> s[i];
	}
	for(int i=0;i<10005;i++){
		for(int i=0;i<a[i];i++){;
			m[i]=s[i];
		}
    }
    for(int i=10005;i>0;i--){
    	b[i]=m[i];
	}
	for(int i=0;i<10005;i++){
		if(b[i]!=m[i]){
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}
