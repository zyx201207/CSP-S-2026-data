#include <bits/stdc++.h>
using namespace std;
int n,num,ans;
string s="";
char zm;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d%s",&num,&zm);
		for(int j=0;j<num;j++){
			s+=zm;
		}
	}
	int en=s.size()/2;
	for(int i=0;i<en;i++){
		if(s[i]!=s[s.size()-1-i]){
			ans++;
		}
	}
	
	cout<<ans;
	return 0;
}
