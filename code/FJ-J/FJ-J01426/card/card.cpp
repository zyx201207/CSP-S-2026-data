#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],b[N],c[N],sga[N];
bool flag=true;
vector<int> sum;
stack<int> num;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
		if(a[i]!=a[i-1]){
			c[a[i]]=i;
		}
		if(a[i]<a[i-1]){
			flag=false;
		}
	}
	if(flag){
		for(int i=1;i<=m;i++){
			cout<<b[i]+c[i]-1<<" ";
		}
		return 0;
	}else{
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				bool fl=false;
				for(int k=0;k<sum.size();k++){
					if(sum[k]==0){
						continue;
					}
					if(sum[k]==j){
						fl=true;
					}
					if(fl){
						sum[k]=0;
						num.pop();
					}
				}
				num.push(a[j]);
				sum.push_back(a[j]);
			}
			while(!num.empty()){
				int x=num.top();
				sga[x]++;
				num.pop();
			}
		}
		for(int i=1;i<=m;i++){
			cout<<sga[i]<<" ";
		}
	}
	return 0;
}
