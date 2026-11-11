#include<bits/stdc++.h>
using namespace std;
const int maxn=200090;
struct d{
	int lo;
	char ch;
}s[maxn];
int n;int a[maxn];char c[maxn];int l=0;long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>c[i];
		s[l].lo=a[i];
		s[l++].ch=c[i];
	}
	int l=0,r=n-1;
	while(l<=r){
		if(s[l].ch!=s[r].ch){
			if(s[l].lo>s[r].lo){
				s[l].lo-=s[r].lo;
				ans+=s[r].lo;
				r--;
			}
			else if(s[l].lo<s[r].lo){
				s[r].lo-=s[l].lo;
				ans+=s[l].lo;
				l++;
			}
			else{
				ans+=s[l].lo;
				l++;r--;
			}
		}
		else{
			if(s[l].lo>s[r].lo){
				s[l].lo-=s[r].lo;
				r--;
			}
			else if(s[l].lo<s[r].lo){
				s[r].lo-=s[l].lo;
				l++;
			}
			else{
				l++;r--;
			}
		}
	}
	cout<<ans;
	return 0;
}
