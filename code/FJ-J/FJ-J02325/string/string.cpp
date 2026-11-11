#include<bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	string s="";
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=b[i];
		}
	}
	int xg=0;
	int gs=0;
	for(int i=1;i<=n;i++){
		gs+=a[i];
	}
	if(gs%2==0){
		for(int i=gs/2;i<=s.size();i++){
			if(s[i]!=s[gs-i]){
				xg++;
			}
		}
	}
	else{
		for(int i=gs/2+1;i<=s.size();i++){
			if(s[i]!=s[gs-i-1]){
				xg++;
			}
		}
	}
	cout<<xg;
	return 0;
}
