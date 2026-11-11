#include<bits/stdc++.h>
using namespace std;
string a[500005];
int p[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		string s="";
		for(int j=i;j<=n;j++){
			if(s.find(a[j])!=-1){
				s.erase(s.find(a[j])+1,(long long)(s.size())-1-(long long)(s.find(a[j])));
			}else{
				s+=" ";
				s+=a[j];
			}
		}
		for(int j=1;j<=m;j++){
			long long t=1,l=0;
			for(int k=s.size()-1;k>=0;k--){
				if(s[k]>='0'&&s[k]<='9'){
					l+=(s[k]-'0')*t;
					t*=10;
				}else{
					t=1;
					if(l==j){
						p[j]++;
					}
					l=0;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",p[i]);
	}
	return 0;
}
