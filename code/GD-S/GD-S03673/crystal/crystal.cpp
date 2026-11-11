#include<bits/stdc++.h> 
using namespace std;
const int N=5*1e5+5;
int a[N],av;
bool sm=false;
int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout); 
	int n,m,s=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		if(a[i]==a[i+1]){
			sm=true;
			av=a[i];
		}
	}
	if(!sm){
		for(int i=1;i<=n;i++){
			av+=a[i];
		}
		av/=n;
	}
	for(int i=1;i<=n;i++){
		if(m==0){
			break;
		}
		if(a[i]!=av){
			while(a[i]!=av){
				m--; 
				a[i]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1]){
			s++;
		}
	}
	cout<<s;
	return 0;
}
