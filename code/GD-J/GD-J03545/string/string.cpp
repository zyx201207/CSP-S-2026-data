#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
struct g{
	long long num;
	char c;
}st[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>st[i].num>>st[i].c;
	}
	long long ans=0;
	int l=1,r=n;
	int ch=st[r].num;
	while(l<r){
		while(st[l].c==st[r].c&&st[l].num<ch){
			ch-=st[l].num;
			l++;	
		}
		if(st[l].c==st[r].c&&st[l].num>=ch){
			r--;
			st[l].num-=ch;
			ch=st[r].num;
		}
		if(st[l].c!=st[r].c&&st[l].num<ch){
			ans+=st[l].num;
			ch-=st[l].num;
			l++;
		}
		if(st[l].c!=st[r].c&&st[l].num>=ch){
			ans+=ch;
			st[l].num-=ch;
			r--;
			ch=st[r].num;
		}
	}
	cout<<ans;
	return 0;
}

