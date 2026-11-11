#include<bits/stdc++.h>
using namespace std;
long long  e=0;
int q,w;
long long a[200006];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>q>>w;
	for(int i=0;i<q;i++){
		cin>>a[i];
	}
	int c[q-1]={0};
	for(int i=1;i<q;i++){
		vector<int>b;
		for(int j=i;j<q;j++){
			for(int i2=0;i2<q;i2++){
				if(a[j]==b[i2]){
					for(int i3=0;i3<i2;i3++){
						a[i3]=0;
					}
					break;
				}
			}
		}
		for(int j=0;j<b.size();j++){
			if(b[j]!=0)c[b[j]]++;
		}
	}
	for(int i=0;i<q-1;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
