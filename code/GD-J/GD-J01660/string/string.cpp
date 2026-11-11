#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
int n,ans=0;
cin>>n;
for(int i=1;i<=n;i++){
	int xxx;
	char ccc;
	cin>>xxx>>ccc;
	for(int i=1;i<=xxx;i++){
		s=s+ccc;
	}
}
int sizeee=s.size();
//cout<<sizeee<<endl;
for(int i=1;i<=sizeee/2+1;i++){
	if(s[i]!=s[sizeee+1-i]){
	ans++;	
//	cout<<i<<"    "<<sizeee-i;
	}
}cout<<ans;
} 
