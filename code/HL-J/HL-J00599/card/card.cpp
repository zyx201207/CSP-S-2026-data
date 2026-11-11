#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=5e5+55;
ll n,m,a[M];
int main(){
	freopen("card2.in","r",stdin);
	freopen("card2.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}if(n==2){
		if(a[1]==a[2])cout<<2;
		else if(a[1]>a[2])cout<<"2 1";
		else cout<<"1 1";
	}
	else if(m==2){
		ll q=1,ans[3]={};
		while(q<=n){
			if(a[q]==a[n]){
				ans[a[n]]++;
			}else{
				ans[a[n]]++,ans[a[q]]++;
			}q++;
		}for(int i=1;i<=m;i++){
			cout<<ans[i]<<' ';
		}
	}
	else if(n<=5000&&m<=3000){
		ll q=1,ans[5008]={},b[5008]={};
		while(q<=n){
			stack<ll>s;
			for(int i=q;i<=n;i++){
				if(b[i]){
					while(s.top()!=a[i])s.pop();
					s.pop();
				}s.push(a[i]);
				b[a[i]]=1;
			}while(!s.empty()){
				ans[s.top()]++;
				s.pop();
			}q++;
			memset(b,0,sizeof b);
		}for(int i=1;i<=m;i++){
			cout<<ans[i]<<' ';
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

