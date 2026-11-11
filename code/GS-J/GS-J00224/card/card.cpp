#include<bits/stdc++.h>
using namespace std;

int n,m,a[500005],ji[500005],s;
bool f=true;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int ii=0;ii<n;ii++){
		s=ii;
		for(int i=ii;i<n;i++){
			for(int j=i+1;j<n;j++){
				f=true;
				if(a[i]==a[j]){
					s=j;
					i=j;
				}
			}
		}
		for(int i=0;i<n;i++){
			ji[a[s+i]]++;
			cout<<a[s+i]<<endl;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ji[i]<<' ';
	}
	return 0;
}
