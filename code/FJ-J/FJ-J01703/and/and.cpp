#include<bits/stdc++.h>
using namespace std;
struct node{
	string s;
	int cnt1=0;
	int oct;
}s[200005];
bool cmp(node a,node b){
//	cout<<"kale";
	if(a.cnt1!=b.cnt1){
		return a.cnt1>b.cnt1;
	}
	else{
		return a.oct>b.oct;
	}
}
string bi(int x){
	string ans="";
	while(x!=0){
//		cout<<"kale";
		if(x%2==0){
			ans='0'+ans;
		}
		else{
			ans='1'+ans;
		}
		x/=2;
	}
//	cout<<ans<<" ";
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		s[i].s=bi(x);
		s[i].oct=x;
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<s[i].s.size();j++){
			if(s[i].s[j]=='1'){
				s[i].cnt1++;
			}
		}
	}
	sort(s+1,s+1+n,cmp);
	unsigned int ans;
	for(int i=1;i<=m;i++){
		if(i==1){
			ans=s[i].oct;
		}
		else{
			ans&=s[i].oct;
		}
//		cout<<s[i].oct<<" "<<s[i].cnt1<<" "<<ans<<endl;
	}
//	for(int i=1;i<=m;i++){
//		cout<<s[i].oct<<" "<<s[i].cnt1<<endl;
//	}
	cout<<ans;
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
