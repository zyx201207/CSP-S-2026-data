#include <bits/stdc++.h>
using namespace std;
struct st{
	int a;char b;
};
long long n,ans,m;st t[100009];
string ch;
int main(){
	freopen("string .in","r",stdin) ;
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t[i].a>>t[i].b;
	 	for(int j=0;j<t[i].a;j++){
	 		ch.push_back(t[i].b);
		 }
		 m+=t[i].a;
	}
	int nm=m/2;
	for(int i=0;i<nm;i++){
		if(ch[i]!=ch[m-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
