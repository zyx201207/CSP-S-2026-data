#include <bits/stdc++.h>
using namespace std;

struct node{
	long long a,b;
	string s;
}two[200005];

node yu(node x,node y){
	long long ans=0;
	string str="";
	for (int i=0;i<int(max(x.s.size(),y.s.size()));i++){
		if (x.s[i]==1&&y.s[i]==1){
			str+=1;
			ans+=pow(2,i);
		}else 
			str+='0';
	}
	node z={ans,0,str};
	return z;
}

bool cmp(node x,node y){
	return x.b>y.b;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	long long n,m;
	cin>>n>>m;
	
	for (int i=0;i<n;i++){
		cin>>two[i].a;
		long long x=two[i].a;
		long long cnt=0;
		string ing="";
		
		while (x!=0){
			ing+=x%2;
			if (x%2==1){
				cnt++;
			}
			x/=2;
		}
		
		two[i].b=cnt;
		two[i].s=ing;
	}
	
	sort (two,two+n,cmp);
	
	node z;
	for (int i=1;i<n-1;i++){
		z=two[0];
		z=yu(two[i],z);
	}
	cout<<z.a;
	
	return 0;
}
