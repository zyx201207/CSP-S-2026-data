#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
string s;
struct node{
	int ai;
	char ci;
}a[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].ai>>a[i].ci;
	}
	s='\0';
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i].ai;j++){
			s+=a[i].ci;
		}
	}
	int ji=0;
	int l=1;
	int r=s.length()-1;
	while(l<r){
		if(s[l]!=s[r]){
			ji++;
		}
		l++;
		r--;
	}
	cout<<ji<<endl;
	return 0;
}

