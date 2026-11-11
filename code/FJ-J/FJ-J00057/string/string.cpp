#include<bits/stdc++.h>
using namespace std;
long long q,w,e,r,l,a[10101000];
char s[1010000];
string s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>a[i]>>s[i];
	}
	l=1;
	r=q;
	while(l<r){
		if(a[l]<=a[r]){
			if(s[l]!=s[r]){
				
				e+=a[l];
			}
			
			a[r]-=a[l];
			l++;
		}
		else{
			if(s[l]!=s[r]){
				e+=a[r];
			}
			
			a[l]-=a[r];
			r--;
		}
		
	}
	cout<<e;
	return 0;
}
