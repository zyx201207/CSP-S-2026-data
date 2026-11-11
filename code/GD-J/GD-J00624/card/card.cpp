#include<bits/stdc++.h>
#define ll long long
using namespace std;
int b[555555],cnt[555555];
char a[555555];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,p;
	cin>>n>>m;
	string s="",sk;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int j=1;j<=n;j++){
		for(int i=j;i<=n;i++){
			s+=a[i];
			if(b[a[i]-'0']==1){
				for(int k=0;k<s.size();k++)if(s[k]==a[i]){
					p=k;break;
				}//cout<<s<<" "<<p<<"\n";
				for(int k=p+1;k<s.size();k++){
					b[a[k]-'0']=0;
				}
				int len=s.size(); 
				s.erase(p+1,len-p);
			}
			else {
				b[a[i]-'0']++;
			}
		}
		for(int i=0;i<s.size();i++){
			 cnt[s[i]-'0']++;
		}
		s="";
		memset(b,0,sizeof(b));
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	cout<<"\n";
	
	return 0;
} 
//4 3 1 2 1 3
