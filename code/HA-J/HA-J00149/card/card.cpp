#include<bits/stdc++.h>
using namespace std;
string s,s1;
int n,m,a[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		s+=a+'0';
	}
	for(int i=1;i<=n;i++){
		s1="";
		for(int j=i-1;j<s.size();j++){
			if(s1.find(s[j])!=-1){
				int f=s1.find(s[j]);
				string s2=s1;
				s1="";
				for(int k=0;k<=f;k++)s1+=s2[k];
			}else s1+=s[j];
		}
		for(int j=0;j<s1.size();j++)a[s1[j]-'0']++;
	}
	for(int i=1;i<=m;i++)printf("%d ",a[i]);
	return 0;
}
