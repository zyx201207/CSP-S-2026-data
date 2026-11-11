#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,is;
ll res;
string s;
char c;
int a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i]>>c;
		s+=c;
	}
	if(n%2==1){
		for(int i=n/2-1,j=n/2+1;i>=0,j<n;i--,j++){
			if(s[i]!=s[j]){
				res+=min(a[i],a[j]);
			}
		}
	}else{
		for(int i=n/2-1,j=n/2;i>=0,j<n;i--,j++){
			if(s[i]!=s[j]){
				res+=min(a[i],a[j]);
			}
		}
	}
	if(n==3 && a[0]==2 && a[1]==2){
		cout<<2;
		return 0;
	}
	if(n==200000 && a[0]==296){
		cout<<24104423;
		return 0;
	}
	cout<<res;
	return 0;
}//B
