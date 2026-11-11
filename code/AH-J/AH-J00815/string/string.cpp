#include<bits/stdc++.h>
using namespace std;
int n;
string s="";
struct node{
	char c;
	int t;
}a[200100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].t>>a[i].c;
		int cnt=a[i].t;
		while(cnt--){
			s+=a[i].c;
		}
	}
	cout<<min(a[0].t,a[1].t);
	return 0;
}
