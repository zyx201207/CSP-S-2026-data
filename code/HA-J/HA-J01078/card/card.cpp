#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
int c[99999],d[99999];
vector<long long>a,b;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>k;
		b.push_back(k);
	}
	k=0;
	for(int i=1;i<=n;i++){
		for(int j=i-1;j<n;j++){
			if(c[b[j]]==0){
				a.push_back(b[j]);
				k++;
				c[b[j]]=k;
			}else{
				for(int l=k-1;l>=c[b[j]];l--){
					c[a[l]]=0;
					a.pop_back();
				}
				k=c[b[j]];
			}
		}
		while(!a.empty()){
			c[a.back()]=0;
			d[a.back()]++;
			a.pop_back();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
