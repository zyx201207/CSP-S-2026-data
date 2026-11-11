#include<bits/stdc++.h>
using namespace std;
int  a[200001];
char c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	bool f=true;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<n;i++){
		if(a[i]!=a[i+1]){
			f=false;
		}
	}
	int o=0;
	if(f){
		for(int i=1;i<=n;i++){
			s[o]=c[i];
			o++;
		}
		long long num=0;
		if(o%2==0){
			for(int i=0;i<o/2;i++){
				if(s[i]!=s[o-i-1]){
					num+=a[i+1];
				}
			}
		}else{
			for(int i=0;i<(o-1)/2;i++){
				if(s[i]!=s[o-i-1]){
					num+=a[i+1];
				}
			}
		}
		cout<<num;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s[o]=c[i];
			o++;
		}
	}
	long long num=0;
	if(o%2==0){
		for(int i=0;i<o/2;i++){
			if(s[i]!=s[o-i-1]){
				num++;
			}
		}
	}else{
		for(int i=0;i<(o-1)/2;i++){
			if(s[i]!=s[o-i-1]){
				num++;
			}
		}
	}
	cout<<num;
	return 0;
}
