#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
char a[N+5];
string s;
int k,ans[300005];
bool v[N+5];
bool che(char x){
	for(int i=0;i<s.size();i++){
		if(s[i]==x&&!v[i]){
			k=i;
			return true;
		}
	}
	return false;
}
void cle(int a){
	for(int i=a;i<s.size();i++){
		v[i]=true;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s="";
		memset(v,0,sizeof(v));
		for(int j=i;j<=n;j++){
			if(che(a[j])){
				cle(k);
			}
			s+=a[j];
		}
		for(int j=0;j<s.size();j++){
			if(!v[j])ans[(s[j]-'0')]++;
		}
	}
	for(int i=1;i<=m;i++){
		if(ans[i]!=0)cout<<ans[i]<<" ";
	}
	return 0;
}
