#include<bits/stdc++.h>
using namespace std;
int n,m,a[500000],s[300005];
bool f[300005];
stack<int>desk;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(!f[a[j]]){
				desk.push(a[j]);
				f[a[j]]=true;
			}
			else{
				while(true){
					if(desk.top()==a[j]){
						break;
					}
					f[desk.top()]=false;
					desk.pop();
				}
			}
		}
		while(true){
			if(desk.empty()){
				break;
			}
			desk.pop();
		}
		for(int j=1;j<=m;j++){
			if(f[j]){
				s[j]++;
				f[j]=false;
			}
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",s[i]);
	}
	return 0;
} 
