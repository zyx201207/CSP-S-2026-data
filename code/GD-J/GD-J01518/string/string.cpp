#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200005];
string s="",c;
bool vis=0;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		string c1,c2;
		for(int i=1;i<=2;i++){
		    if(i>1){
		    	cin>>a[i]>>c2;
			}else{
				cin>>a[i]>>c1;
			}
	    }
	    if(c1[0]!=c2[0]){
			cout<<min(a[1],a[2]);
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c;
		if(a[i]!=1)vis=1;
		for(int j=1;j<=a[i];j++){
			s+=c;
		}
	}
	if(!vis){
		int x=n/2,j;
		if(n%2==0)j=x;
		else j=x+1;
		for(int i=x-1;i>=0;i--){
			if(s[i]!=s[j])break;
			else x--;
			j++;
		}
		cout<<x;
		return 0;
	}else{
		int x=s.size()/2,j;
		if(n%2==0)j=x;
		else j=x+1;
		for(int i=x-1;i>=0;i--){
			if(s[i]!=s[j])break;
			else x--;
			j++;
		}
		cout<<x;
		return 0;
	}
	return 0;
}
