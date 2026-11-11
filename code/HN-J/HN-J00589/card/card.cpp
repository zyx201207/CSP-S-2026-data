#include<bits/stdc++.h>
using namespace std;
const int N=5E5+5,M=3E5+100;
char a[N];
int t[M];
string s1,s2;
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		s1="";
		s2="";
		for(int j=i;j<=n;j++){
			s2="";
			if(s1.find(a[j])>=0&&s1.find(a[j])<s1.size()){
				for(int z=0;z<s1.find(a[j]);z++){
					s2+=s1[z];
				}
				s1=s2;
			}
			s1+=a[j];
			cout<<s1<<endl;
		}
		for(int z=0;z<s1.size();z++){
			t[s1[z]]++;
		}
		s1="";
		s2="";
	}
	for(int i='1';i<='0'+m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}
