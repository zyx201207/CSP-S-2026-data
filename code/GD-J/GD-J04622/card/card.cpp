#include<bits/stdc++.h>
using namespace std;
int a[300005];
int b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	string s="";
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int t=-1; 
			for(int k=0;k<s.length();k++){
				if(s[k]==char(a[j]+48)){
					t=k;
					break;
				}
			}
			if(t==-1){
				s=s+char(a[j]+48);
			}else{
				s=s.substr(0,t);
			}
		}
		for(int j=0;j<s.length();j++){
			b[s[j]-48]++;
		}
		s="";
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<' ';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
