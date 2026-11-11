#include<bits/stdc++.h>
using namespace std;
struct node{
	long long v;
	char c;
};
node s[200005];
long long n,ans,l,r;
int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
	for(int i=0;i<n;i++)cin>>s[i].v>>s[i].c;
    r=n-1;
    while(l<r){
        if(s[l].c!=s[r].c) ans+=min(s[l].v,s[r].v);
        if(s[l].v==s[r].v){
			l++;
			r--;
		}
		else if(s[l].v<s[r].v){
			s[r].v-=s[l].v;
			l++;
		}
		else if(s[l].v>s[r].v){
			s[l].v-=s[r].v;
			r--;
		}
    }
    cout<<ans;
}
