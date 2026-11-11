#include<bits/stdc++.h>
using namespace std;
int a[500010],t[300010];
int n,x;
void f(int i){
	int m[500010];
	for(int j=i;j<=n;j++){
		int k=1;
		while(m[k]!=0){
			if(a[j]=m[k]){
				m[k]=a[j];
				k++;
				while(m[k]!=0){
					m[k]=0;
					k++	;
				}
			}
			k++;
		}
	}
	int k=1,sum=0;
	while(m[k]!=0){
		k++;
	}
	for(int j=1;j<=k--;j++){
		t[m[j]]++;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>x;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		f(i);
	}
	for(int i=1;i<=x;i++){
		cout<<t[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
