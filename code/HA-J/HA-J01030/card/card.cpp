#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],ans,t[300005];
string s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(n<=500){
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				ll k=s.find((char)a[j]+'0');
				if(k!=-1){
					s.erase(k,s.size()-k);
				}
				s+=((char)a[j]+'0');
			}
			while(!s.empty()){
				t[(ll)s[0]-'0']++;
				s.erase(0,1);
			}
		}
		for(int i=1;i<=m;i++)cout<<t[i]<<' '; 
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			if(a[n]==1&&a[i]==1)t[1]++;
			else if(a[n]!=a[2])t[1]++,t[2]++;
			else t[2]++;
		}
		cout<<t[1]<<' '<<t[2];
	}
	else if(m==1){
		cout<<n;
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=n;i>=1;i--){
			if(i==n)t[a[i]]+=i;
			else if(a[i]!=a[i+1]){
			 	t[a[i]]+=i;
			}
		}
		for(int i=1;i<=m;i++)cout<<t[i]<<' '; 
	}
	return 0;
}
