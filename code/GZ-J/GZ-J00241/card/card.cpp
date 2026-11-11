//GZ-J00241 个人报名 吴狄阳 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N];
int b[N];
int c[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=0;
	}
	for(int i=1;i<=n;i++){
		b[a[i]]++;
	}
	for(int k=1;k<=n;k++){
		for(int j=k;j<=n;j++){
			for(int i=n;i>=j;i--){
				if(b[a[i]]==1){
					c[a[i]]++;
				}
				else{
					c[a[i]]++;
					continue;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<c[a[i]];
	}
}
