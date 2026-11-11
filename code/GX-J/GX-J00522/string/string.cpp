#include<bits/stdc++.h>
using namespace std;
char s[2000000000];
int f;
int t;
int cnt1,cnt2;
int n;
long long a;
char a1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>a1;
		for(int j=1;j<=a;j++){
			s[cnt1]=a1;
			cnt1++;
		}
	}
	t = strlen(s);
	for(int i=0;i<t;i++){
		for(int j=0;j<t;j++){
			if(s[i]==s[j]&&i+j==t-1){
				cnt2++;
			}
		}
	}
	if(cnt2==t){
		cout<<0;
		return 0;
	}
	long long l,r,cnt3=0;
	l=0;
	r=t-1;
	while(l<=r){
		if(s[l]!=s[r]){
			cnt3++;
			l++;
			r--;
		}else{
			l++;
			r--;
		}
	}
	cout<<cnt3;
	return 0;
}
