//GZ-J00223 ╨нвсд╬ 
#include<bits/stdc++.h>
using namespace std;
int n,m;
string s,p;
int a[100010],b[100010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s="";
		for(int j=i;j<=n;j++){
			p="";
			s+=a[j]+48;
			for(int k=0;k<s.size();k++){
				p+=s[k];
				if(s[k]-48==a[j]){
					break;
				}
				
			}
			s=p;
		}
		for(int k=0;k<=s.size();k++){
			b[s[k]-48]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
}
