//GZ-J00053 贵阳市第一实验中学 王果然
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
int a[N];
char b[N];
char s[N];
int cnt=INT_MAX;
int cnt1;
int cnt3;
int hw(){
	for(int i=1;i<=cnt1/2; i++) {
		if(s[i]!=s[cnt1-i+1]) {
			return 2;
		}	
	}
	return 1;
}

int main() {
// freopen("string.in","r",stdin);
// freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		cin>>b[i];
	}
	for(int i=1; i<=n; i++) {
		for(int j=cnt1+1; j<=a[i]+cnt1; j++) {
			s[j]=b[i];
		}
		cnt1+=a[i];
	}
	if(hw()==1) {
		cout<<0;
		return 0;
	} else {
		for(int i=1;i<=cnt;i++){
			s[i]=s[cnt1-i+1];
			cnt3++;
			if(hw()==1){
				cout<<cnt3;
				return 0;
			}
			
		}
	}
	cout<<cnt;
	return 0;
}
