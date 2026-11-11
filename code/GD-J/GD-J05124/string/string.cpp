#include<bits/stdc++.h>
using namespace std;
struct node{
	long long x;
	char ch;
}a[200010];
int n;
long long sum=0;
string st="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].ch;
		int m=a[i].x;
		char c=a[i].ch;
		for(int i=1;i<=m;i++){
			st+=c;
		} 
	}
	//cout<<st<<'\n';
	long long ans=0;
	for(int i=0,j=st.size()-1;i<=j;i++,j--){
		if(st[i]!=st[j]){
			ans++;
		}
	}
	cout<<ans;
//	int st1,st2;
//	if(sum%2==0){
//		st1=sum/2;
//		st2=st1+1;
//	}
//	else {
//		st1=sum/2;
//		st2=st1+2;
//	}
	
	return 0;
} 
