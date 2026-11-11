#include<bits/stdc++.h>
using namespace std;
string s;
char a[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];	
	} 
	for(int i=1;i<=n;i++){
		string s1;
		for(int j=i;j<=n;j++){
			int p=0;
			if(!s.find(a[j])) s+=a[j];
			else{
				for(int k=1;k<i;k++){
					s1[i]=s[i];
					p=1;
					break;
				}		
			}
			if(p==1) break;
			s=s1;
			if(s1.size()==1){
				cout<<s1[1]<<" ";
				s="";
				for(int j=1;j<=n;j++){
					s+=a[j];
				}
			}
		}
		
	}
	return 0;
}
