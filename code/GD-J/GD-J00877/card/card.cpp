#include<bits/stdc++.h>
using namespace std;
long long n,m,s;
stack<int> a;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	long long d[n+1]={},b[m+1]={},c[m+1]={};
	for(int l=1;l<=n;l++){
		cin>>d[l];
	}
	for(int i=n;i>=1;i--){
		for(int j=i;j<=n;j++){
			s=d[j];
			if(b[s]==0){
				a.push(s);
				b[s]++;
			}
			else{
				while(a.top()!=s){
					b[a.top()]--;
					a.pop();
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(b[j]>0){
				c[j]++;
			}
			b[j]=0;
		}
		while(!a.empty()){
			cout<<a.top()<<" ";
			a.pop();
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
