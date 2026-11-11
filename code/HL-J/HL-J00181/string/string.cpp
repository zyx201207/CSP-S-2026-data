#include<bits/stdc++.h>
using namespace std;

struct node{
	long long l;	
	string str;
};

node a[200010];
string ans;
long long n;
long long m,st=1,et,tl,tll;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].l>>a[i].str;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i].l;j++){
			ans+=a[i].str;
		}
	}
	tl=ans.size();
	
	for(int i=1;i<=tl/2;i++){
		if(ans[i-1]!=ans[tl-i]){
			m++;
		}
	}
	cout<<m;

    return 0;
}
