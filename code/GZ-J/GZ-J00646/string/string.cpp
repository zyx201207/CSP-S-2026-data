//GZ-J00646		兴义市弘毅中学		马志宸奕	 
#include<bits/stdc++.h>
using namespace std;

string s;
int n,a,num,ans;
char c;


int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s+=c;
		}
		num+=a;
	}
	if(num%2==0){
		for(int i=num/2-1;i>=0;i--){
			int j=num-i;
			if(s[i]!=s[j]){
				s[i]=s[j];
				ans++;
			}
		}
	}
	else{
		for(int i=num/2-1;i>=0;i--){
			int j=num-i-1;
			if(s[i]!=s[j]){
				s[i]=s[j];
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
