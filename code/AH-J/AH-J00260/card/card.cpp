#include<bits/stdc++.h>
using namespace std;
int a[1000005],cnt[1000005];
bool s[1000005];
stack<int> b;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(s[a[i]]==0){
				s[a[i]]=1;
				b.push(a[i]);
			}
			else{
				while(b.top()!=a[i]){
					b.pop();
				}
			}
		}
		while(!b.empty()){
			cnt[b.top()]++;
		}
		for(int j=1;j<=n;j++){
			s[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
