#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],c[300005];
string mo(int x){
	string s="";
	int flag=x;
	for(int i=x;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]==a[i]){
				flag=j;
				i=flag;
				break;
			}
		}
	}
	for(int i=flag;i<=n;i++)s+=char(48+a[i]);
	return s;
}
void check(string s){
	for(int i=0;i<s.size();i++)c[int(s[i]-48)]++;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		check(mo(i));
		cout<<mo(i)<<endl;
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<" ";
	return 0;
}
