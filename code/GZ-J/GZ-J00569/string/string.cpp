//GZ-J00569，彭三立，华东师范大学附属贵阳学校 
#include<bits/stdc++.h>
using namespace std;
const int N= 1e5+10;
int n,cnt=0;
int m;
int a[N];
char c[N];
string s;
	int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];	
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}	

	if(s.size()%2!=0){
		m=s.size()/2+1;
		for(int i=1;i<m;i++){
			if(s[i]==s[s.size()-i+1]){
				cnt+=0;
				
			}
			else if(s[i]!=s[s.size()-i+1]){
				cnt++;
				
			}
		}
	}
	else {
		m=s.size()/2;
		for(int i=1;i<=m;i++){
			if(s[i]==s[s.size()+1-i]){
				cnt+=0;
			}
			else{
				cnt++;
			
			}
		}
	}
	
	
	
	cout<<cnt;
	return 0;
}
