#include<bits/stdc++.h>
using namespace std;
long long n,m,c[300005];
char a[500005];
map <char,long long> b;
string s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int x=2;x<=n+1;x++){
		s="";
		for(int j=1;j<=m;j++){
			b['0'+j]=0;
		}
		for(int i=x-1;i<=n;i++){
			b[a[i]]++;
			if(b[a[i]]==2){
				for(int j=s.find(a[i]);j<s.size()-1;){
					b[s[j+1]]=0;
					s.erase(j+1,1);
				}
				b[a[i]]--;
			}
			else{
				s+=a[i];
			}
		}
		for(int j=1;j<=m;j++){
			if(b['0'+j]==1){
				c[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	} 
	return 0;
}
