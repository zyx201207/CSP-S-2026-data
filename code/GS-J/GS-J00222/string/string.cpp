#include <bits/stdc++.h>
using namespace std;
char c[200005];
int n,a[200005],cnt;
string s="";
int main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>n;
	for (int i=1 ; i<=n ; i++){
		cin >>a[i] >>c[i];
		for (int j=1 ; j<=a[i] ; j++){
			s+=c[i];
		}
	}
	int l=s.size();
	if (l%2!=0){
		int l1=l/2;
		for (int i=1 ; i<=l/2 ; i++){
			 if(l1-i!=l1+i){
			 	cnt++;
			 }
		}
	}
	else{
		int l1=l/2,l2=l/2+1;
		for (int i=0 ; i<l/2 ; i++){
			 if(l1-i!=l2+i){
			 	cnt++;
			 }
		}
	}
	cout <<cnt;
	return 0;
}
