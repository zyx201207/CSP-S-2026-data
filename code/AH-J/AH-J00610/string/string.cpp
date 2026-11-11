#include<bits/stdc++.h>
using namespace std;
struct str{
	long long a;
	char c;
}p[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,s=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].a>>p[i].c;
	}
	long long l=1,r=n;
	while(l<r){
		//cout<<l<<" "<<r<<" "<<s<<" ";
		if(p[l].c!=p[r].c) s+=min(p[l].a,p[r].a);
		//cout<<p[l].a<<" "<<p[r].a<<" "<<s<<"\n";
		if(p[l].a==p[r].a){
			p[r].a=0;
			p[l].a=0;
			l++;
			r--;
			continue;
		}
		else if(p[l].a<p[r].a){
			p[r].a-=p[l].a;
			p[l].a=0;
			l++;
			continue;
		}
		else if(p[l].a>p[r].a){
			p[l].a-=p[r].a;
			p[r].a=0;
			r--;
			continue;
		}
	}
	cout<<s;
	return 0;
}
