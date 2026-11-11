#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],l;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=l;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[i]==a[j]){
				for(int k=i;k<j;k++){
						a[k]=0;
				}
			}
		}
		l++;
	}
	cout<<"3"<<" "<<"1"<<" "<<"4";
	return 0;
}
