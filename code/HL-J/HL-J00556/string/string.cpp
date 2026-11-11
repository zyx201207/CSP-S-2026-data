#include<bits/stdc++.h>
using namespace std;
string s,c;
int a[1000];
struct Node{
	int num;
}node[1000];
bool cmp(Node x,Node y){
	return x.num>y.num;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n>>c;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=a[i]+'0'*c[i];
	}
	cout<<s;
	for(int i=1;i<=2*n;i++){
		if(s[i]!=s[n-i+1]){
			s[i]=s[n-i+1];
			node[i].num++;
		}
		else{
			cout<<"0";
		}
	}
	sort(node+1,node+n+1,cmp);
	for(int i=1;i<=2*n;i++){
		cout<<node[i].num;
	}
	return 0;
}

