#include<bits/stdc++.h>
using namespace std;
int n,m;
string s[3]={""};
char a1;
int tiao=0;
bool pd(string s3,char a){
	if(s3.size()>0)
		for(int i=s3.size()-1;i>=0;i--){
			if(s3[i]==a){
				tiao=i;
				return true;
			}
		}
	return 0;
}
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a1;
		s[0]+=a1;
	}
	int shu[300005]={0};
	for(int i=0;i<n;i++){
		int t=1;
		s[1]="";
		s[2]="";
		for(int j=i;j<n;j++){
			s[t]+=s[0][j];
			if(pd(s[t],s[0][j])){
				int t1=t;
				if(t==1)
					t=0;
				else t=1;
				for(int i=0;i<=tiao;i++){
					s[t]+=s[t1][i];
				}
				s[t1]="";
			}
		}
		for(int j=0;j<s[t].size();j++){
			shu[s[t][i]-48]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<shu[i]<<" ";
	} 
	
	
	return 0;
}
