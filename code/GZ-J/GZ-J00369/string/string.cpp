//GZ-J00369 Íõ×ÓÇ¬
#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
long long n,a[N],an=0;
string c,s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a[i] >> c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	for(int i=0,j=s.size()-1;i<s.size()-1,j>0;i++,j--){
		if(s[i]!=s[j]){
			s[j]=s[i];
			an++;
		}
	}
	cout << an;
	return 0;
}
