#include<bits/stdc++.h>
using namespace std;
int n,a,ans;
string s2,s1,s3;
char c;
string s;
void h(string s2,string s3){
	int count=0;
for(int j=s2.size()-1;j--;j>=0){
	s3[count]=s2[j];
	count++;
}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
			for(int i=1;i<=a;i++){
				s+=c;
			}
	} 
	
	int x;
	for(int i=0;i<=s.size()-1;i++){
		if(s.size()%2==0){
			x=s.size()/2;
		 if(i>s.size()/2-1){
				s2+=s[i];
			}else{
				s1+=s[i];
			}
		}
		if(s.size()%2==1){
			x=s.size()/2;
		if(i>s.size()/2){
				s2+=s[i];
			}else if(i<=s.size()/2-1){
				s1+=s[i];
			}
		}	
	}
 // cout<<s1<<' '<<s2<<x;
	for(int i=0;i<s2.size();i++){
		if(s2[i]!=s1[i])ans++;
	}
		cout<<ans;
	
	return 0;
}
