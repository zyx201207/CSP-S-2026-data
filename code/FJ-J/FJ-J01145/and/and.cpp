#include <bits/stdc++.h>
using namespace std;

string s1;
int m,w;

struct op{
	int x;
	string s;
	long long n;
}a[1000010];

bool cmp(op a,op b){
	if(a.n>b.n) return a.n>b.n;
} 

void andd(int q){
	while(q!=0){
		if(q%2==1) s1+='1';
		else s1+='0';
		q/=2;
	}
}

int pai_e_gsy(string s2){
	int ans=0;
	for(int i=1;i<=s2.size();i++){
		if(s2[i]=='1') ans++;
	} 
	
	return ans;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>m>>w;
	
	for(int i=1;i<=m;i++) cin>>a[i].x;
	
	if(w==1){
		int yy=0;
		for(int i=1;i<=m;i++){
			if(a[i].x>yy) yy=a[i].x;
		}
		
		cout<<yy;
		return 0;
	}
	
	for(int i=1;i<=m;i++){
		s1="";
		int qw=a[i].x;
		andd(qw);
		a[i].s=s1;
		a[i].n=pai_e_gsy(a[i].s);
	}
	
	sort(a+1,a+m+1,cmp);
	int ans=a[1].x;
	
	for(int i=2;i<=w;i++){
		ans&=a[i].x;
	}
	
	cout<<ans;
}
