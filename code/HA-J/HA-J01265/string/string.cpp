#include<bits/stdc++.h>
using namespace std;
long long n,ans=0,m=0,l,p;
string b;
struct st{
	long long a,k;
	char c;
}s[20010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
		if(i==1||s[i].c!=s[i-1].c){
			b+=s[i].c;m++;
		}
		s[m].k+=s[m].a;
		l+=s[i].a;
	}
	m=1;p=b.size();
	if(b.size()==1){
		cout<<0;return 0;
	}
	for(int i=0;i<l/2;){
		if(b[m-1]==b[p-1]){
			i+=min(s[m].k,s[p].k)+1;
			if(s[m].k!=s[p].k){
				if(s[m].k>s[p].k){
					p++;s[m].k-=s[p].k;
				} 
				else{
					s[p].k-=s[m].k;m++;
				} 
			}
			else {
				m++;p++;
			}
		}
		else {
			i+=min(s[m].k,s[p].k)+1;
			ans+=min(s[m].k,s[p].k);
			if(s[m].k==s[p].k){
				m++;p++;
			}
			else if(s[m].k>s[p].k){
				p++;s[m].k-=s[p].k;
			}
			else{
				s[p].k-=s[m].k;m++;
			} 
		}
	}
	cout<<ans;
	return 0;
}
