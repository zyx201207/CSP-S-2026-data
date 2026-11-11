#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
class node{
	public:
		ll a;
		char c;
};
node s[200005];
node b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
	}
	for(int i=n,j=1;i>=1,j<=n;i--,j++){
		b[j].a=s[i].a;
		b[j].c=s[i].c;
	}
	ll sum=0;
	for(int i=1,j=1;i<=n,j<=n;){
		if(b[j].c==s[i].c){
			if(b[j].a>s[i].a){
				b[j].a-=s[i].c;
				i++;
			}else if(b[j].a<s[i].a){
				s[i].a-=b[j].a;
				j++;
			}else {
				i++;
				j++;
			}
		}else{
			sum+=min(s[i].a,b[j].a);
			if(s[i].a<b[j].a){
				b[j].a-=s[i].a;
				i++;
			}else if(s[i].a>b[j].a){
				s[i].a-=b[j].a;
				j++;
			}else{
				i++;
				j++;
			}
		}
	}
	cout<<sum/2;
	return 0;
}
/*
ll sum=0;
	for(int i=1,j=n;i!=n/2,j!=n/2;){
		if(s[i].c!=s[j].c){
			sum+=min(s[i].a,s[j].a);
		}
		if(s[i].a>s[j].a){
			s[i].a-=s[j].a;
			j--;
		}else if(s[i].a<s[j].a){
			s[j].a-=s[i].a;
			i++;
		}else{
			i++;
			j--;
		}
	}
	cout<<sum;
*/
