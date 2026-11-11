#include<bits/stdc++.h>
typedef int ll;
using namespace std;
typedef struct zyb{
	ll l;
	char c;
}ss;
int main(){
	ifstream fin("string.in");
	ofstream fout("string.out");
	ll n;
	long long ans=0;
	fin>>n;
	ss s[200005];
	for(ll i=0;i<n;i++){
		fin>>s[i].l>>s[i].c;
	}
	ll l=0,r=n-1;
	while(l<r){
		if(s[l].l>=s[r].l){
			s[l].l-=s[r].l;
			if(s[l].c!=s[r].c){
				ans+=s[r].l;
			}
			r--;
		}else if(s[l].l<s[r].l){
			s[r].l-=s[l].l;
			if(s[l].c!=s[r].c){
				ans+=s[l].l;
			}
			l++;
		}
	}
	fout<<ans;
	fin.close();
	fout.close();
	return 0;
} 
