#include<bits/stdc++.h>
using  namespace std;
int n[10010],nn[10010],nnn[10010],nnnn[10010];
int mmm[100010];
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
int a,b;
cin>>a>>b;
for(int i=1;i<=a;i++){
	cin>>n[i];
	stack<int>s;
	for(int j=1;j<=a;j++){
		cin>>n[j];
		if(nnn[n[j]]!=0){
			if(s.top()!=n[j]){
				s.pop();
			}
		}
		if(!s.empty()){
			mmm[s.top()]+=1;
			s.pop();
		}
	}
}
for(int i=1; i<=b;i++){
		cout<<mmm[i]<<" ";
	} 
return 0;
}
