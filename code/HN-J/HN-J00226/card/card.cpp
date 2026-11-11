#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int n,m,a[N],box[N];
int tot[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	int len=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=len;++j){
			box[j]=0;
		}
		len=0;
		for(int j=i;j<=n;++j){
			if(len==0){
				box[++len]=a[j];
				continue;
			}
			bool flag=false;
			for(int k=1;k<=len;++k){
				if(box[k]==a[j]){
					len=k,flag=true;
					break;
				}
			}
			if(flag==false){
				box[++len]=a[j];
			}
		}
		for(int j=1;j<=len;++j){
			tot[box[j]]++;
		}
	}
	for(int i=1;i<=m;++i){
		cout<<tot[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
