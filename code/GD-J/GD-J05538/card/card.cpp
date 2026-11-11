#include<bits/stdc++.h>
using namespace std;
long long n,m,a[300005],an[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int b[300005];
		stack<long long >l;
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				b[a[j]]=1;
				l.push(a[j]);
			}
			else{
				while(l.top()!=a[j]){
					b[l.top()]=0;
					l.pop();
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(b[j]!=0){
				an[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<an[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
