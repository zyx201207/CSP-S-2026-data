#include<bits/stdc++.h>
using namespace std;
int n,a,k=0,num=0;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a >> c;
		for(int j=k;j<a+k;j++)s[j]=c;
		k+=a;
	}
	for(int i=0;i<k/2;i++)
		if(s[i]!=s[k-1-i]){
			num++;
		}
	cout << num;
	return 0;
}
