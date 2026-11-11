#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	string s;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	long long cnt=0;
	if(s.size()%2==1){
		for(int i=0,j=s.size()-1;i<s.size()/2,j>s.size()/2;i++,j--){
			if(s[i]!=s[j]){
				cnt++;
			}
		}
		cout<<cnt;
	}else{
		for(int i=0,j=s.size()-1;i<=s.size()/2,j>=s.size()/2+1;i++,j--){
			if(s[i]!=s[j]){
				cnt++;
			}
		}
		cout<<cnt;
	}
	return 0;
}
