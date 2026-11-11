#include<bits/stdc++.h>
using namespace std;
int n,m=0,a[200],l=0;
string s;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("string.in","r",stdin);	
	freopen("string.out","w",stdout);
	string t;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>t;
		a[t[0]]+=m;                          
		l+=m;
		for(int j=1;j<=m;j++){
			s+=t;
		}
	}
	t=s;
	reverse(t.begin(),t.end());
	if(s==t){
		cout<<0;
		return 0;
	}

	sort(a+1,a+150+1,cmp);
	if(l%2==1){
		cout<<l-a[1]-1;
		return 0;
	}
	cout<<l-a[1]; 
	return 0;
}
