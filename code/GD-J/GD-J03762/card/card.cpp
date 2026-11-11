#include<iostream>
#include<cstdio>
using namespace std;
int a[(int)5e5],desk[(int)3e5],sum[(int)3e5];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;cin>>a[i++]);
	for(int i=0;i<n;i++){
		int size=0;
		for(int j=i;j<n;j++){
			for(int k=0;k<size;k++){
				if(desk[k]==a[j]){
					size=k;
					break;
				}
			}desk[size]=a[j];
			size++;
		}for(int j=0;j<size;sum[desk[j++]-1]++);
	}for(int i=0;i<m;cout<<sum[i++]<<' ');
	return 0;
}
