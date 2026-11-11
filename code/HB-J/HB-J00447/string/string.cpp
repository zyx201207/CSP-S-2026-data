#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="",l;
	int n,m,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m;
		cin>>l;
		for(int i=1;i<=m;i++){
			s+=l;
		}
	}
	int i=0,j=s.size()-1;
	while(i<j){
		if(s[i]!=s[j])cnt++;
		i++;
		j--;
	}
	cout<<cnt;
	return 0;
}
