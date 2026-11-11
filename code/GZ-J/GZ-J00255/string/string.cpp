//GZ-J00255 ºÎÐÒ¶ù
#include<bits/stdc++.h>
using namespace std;
string a;
char m; 
long long n,x,cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>m;
		string b;
		for(int j=1;j<=x;j++){
			b=b+m;
		}
		a=a+b;
	}
	for(int i=0,j=a.size()-1;i<a.size()/2;i++,j--){
		if(a[i]!=a[j]){
			cnt++;
		}
	} 
	cout<<cnt;
	return 0;
}
