//GZ-J00195 贵阳市南明区李端棻中学 周熙沅 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="",s1="",s2="";
	int n,cnt=0;
	char a[n+5];
	char c[n+5];
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	n=s.size();
	if(n%2==0){
		for(int i=0;i<n/2;i++){
			s1+=s[i];
		}
		for(int i=n/2;i<n;i++){
			s2+=s[i];
		}
		for(int i=0;i<n/2;i++){
			if(s1[i]!=s2[i]){
				cnt++;
			}
		}
	}else if(n%2==1){
		for(int i=0;i<n/2;i++){
			s1+=s[i];
		}
		for(int i=n/2+1;i<n;i++){
			s2+=s[i];
		}
		for(int i=0;i<n/2;i++){
			if(s1[i]!=s2[i]){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
