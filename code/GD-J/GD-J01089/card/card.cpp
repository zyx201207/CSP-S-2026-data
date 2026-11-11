#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e5+10;
ll n,m,b[N],vis[N],ans;
char a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		string s;
		//cout<<s<<'\n';
		for(int j=1;j<=m;j++){
			b[i]=0;
		}
		for(int j=i;j<=n;j++){
			if(b[a[j]-'0']==0){s+=a[j];b[a[j]-'0']=1;}
			else{
				string s1;
				for(int k=s.find(a[j])-1;k>=0;k--){
					s1+=s[k];
				}
				s=s1+a[j];
			}
		}//cout<<s<<'\n';
		for(int i=0;i<s.size();i++){
			vis[s[i]-'0']++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<vis[i]<<' ';
	}
	return 0;
} 
