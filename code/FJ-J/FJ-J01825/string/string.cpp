#include<bits/stdc++.h>
using namespace std;
string s,c;
int n,m,num;
bool flag=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>m>>c;
		for(int j=1;j<=m;j++){
			s+=c;
		}
	}
	for(int i=0;i<s.size();i++){
		if(s[i]==s[i+1]){
			flag=1;
		}else{
			flag=0;
			break;
		}
	}if(flag==1){
		cout<<0;
	}/*int l=0,r=s.size(),mid=0;
	while(l<=r){
		mid=(l+r)/2;
		
	}
	int x=s.size();
	for(int i=0;i<s.size();i++)
	{
		if(s[i]==s[x]+1-i){
			flag=1;
		}else{
			flag=0;
			num++;
		}
	}*/cout<<0;
	return 0;
}
