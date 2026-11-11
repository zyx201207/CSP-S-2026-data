//GZ-J00177 ∫ÿ¡ºÏœ 68fen
#include<bits/stdc++.h>
using namespace std;
long long n,l,r,cnt,le;
string a="",c;
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>le>>c;
		while(le--){
			a+=c;
		}
	}
	r=a.size()-1;
	while(l<=r){
		if(a[l]!=a[r]) cnt++;
		l++,r--;
	}
	cout<<cnt;
	
	return 0;
}
