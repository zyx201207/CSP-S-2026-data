#include<bits/stdc++.h>
using namespace std;
long long int n,m,l;
long long int a[10000005];
long long int ans[1000005];
long long int f1[1000005];
long long int f2[1000005];

stack<long long int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int i=1;
	while(i<=n){
		l=1;
		for(int j=i;j<=n;j++){
			if(f1[a[j]]==0){
				s.push(a[j]);
				f1[a[j]]=l;
				l++;
			}
			else{
				int o=l;
				for(int k=f1[a[j]];k<=o;k++){
					f1[s.top()]=0;
					s.pop();
					l--;
				}
				s.push(a[j]);
				l++;
				f1[a[j]]=l;
			}
		}
		while(!s.empty()){
			if(f2[s.top()]==0){
				ans[s.top()]+=1;
				f2[s.top()]=1;
			}
			s.pop();
		}
		i++;
		f1[1000005]={0};
		f2[1000005]={0};
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

