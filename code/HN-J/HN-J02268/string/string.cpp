#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
long long m,ans;
struct node{
	int h;
	char j;
}a[100005];
string s;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a[n].h>>a[n].j;
		m+=a[n].h;
		while(a[n].h--)	s+=a[n].j;
	}
	cout<<s;
	for(int i=0;i<m/2;i++){
		int d=m-i-1;
		if(s[i]!=s[d]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
