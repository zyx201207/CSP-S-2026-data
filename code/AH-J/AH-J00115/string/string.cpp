#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,ans;
string s;
struct Node{
	int a;
	char c;
}b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i].a>>b[i].c;
		for(int j=1;j<=b[i].a;j++){
			s=s+b[i].c;
		}
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		if(b[1].c==b[2].c){
			cout<<0;
		}else{
			cout<<min(b[1].a,b[2].a);
		}
		return 0;
	}
	cout<<s<<endl;
	int si=s.size();
	int l=1,r=si;
	if(si==1){
		cout<<0;
		return 0;
	}
	while(l<=r){
		while(s[l]==s[r]){
			l++;
			r--;
		}
		int l1=l;
		while(s[l1]==s[l1+1]&&l1<=si/2){
			l1++;
		}
		int x=l1-l+1;
		int r1=r;
		while(s[r1]==s[r1-1]&&r1>=si/2){
			r1--;
		}
		int y=r-r1+1;
		if(x<y){
			ans+=x;
			l+=y;
			r-=y;
		}else{
			ans+=y;
			r-=x;
			l+=x;
		}
	}
	cout<<ans;
	return 0;
}
