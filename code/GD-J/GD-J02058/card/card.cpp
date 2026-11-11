#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200100],b[200100],t[200100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long tail=0;
		for(int j=i;j<=n;j++){
			bool f=false;
			long tmp;
			for(int k=1;k<=tail;k++){
				if(t[k]==a[j]){
					f=true;
					tmp=k;
					break;
				}
			}
			if(f){
				tail=tmp-1;
			}
			tail++;
			t[tail]=a[j];
			/*for(int i=1;i<=tail;i++){
				cout<<t[i]<<" ";
			}
			cout<<endl;*/
		}
		for(int i=1;i<=tail;i++){
			b[t[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
}
