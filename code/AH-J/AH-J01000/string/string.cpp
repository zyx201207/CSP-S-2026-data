#include<bits/stdc++.h>
using namespace std;
long long ss,a,l,r;
struct st{
	long long number;
	char c;
}f[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a;
	l=1,r=a;
	for(int i=1;i<=a;i++){
		cin>>f[i].number>>f[i].c;
	}
	while(l<r){
		if(f[l].number>f[r].number){
			if(f[l].c!=f[r].c) ss+=f[r].number;
			f[l].number-=f[r].number;
			r--;
		}else if(f[l].number<f[r].number){
			if(f[l].c!=f[r].c) ss+=f[l].number;
			f[r].number-=f[l].number;
			l++;
		}else{
			if(f[l].c!=f[r].c) ss+=f[l].number;
			l++;
			r--;
		}
	}
	cout<<ss;
	return 0;
}
