#include<bits/stdc++.h>
using namespace std;
string y;
int maxn;
void jz(int x){
	while(x!=0){
		y=char(x%2+48)+y;
		x/=x/2;
	}
	return;
}
int shi(string s){
	int x, w=1;
	for(int i=0;i<s.length();i++){
		x+=w*s[i];
		w=w*2;
	}
	return x;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m;
	cin >> n >> m;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[n];
	}
	for(int i=0;i<n;i++){
		for(int j=n-1;j>i;j--){
			jz(a[i]);
			string s1=y;
			jz(a[j);
			string s2=y;
			string s3;
			int l=min(s1.length(),s2.length());
			for(int p=0;p<l;p++){
				s3[p]=0;
				if(s1[p]==1 && s2[p]==1){
					s3[p]=1;
				}
			}
			maxn=max(maxn,shi(s3));
		}
	}
	cout << maxn;
	return 0;
}
