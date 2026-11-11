//GZ-J00430 贵阳市第一实验中学 晏锦桐
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m;
int a[N],b[M];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int t[M]={0};
		for(int j=i;j<=n;j++){
			t[a[j]]=j;
			b[a[j]]++;
			if(t[a[j]]!=0){
				for(int k=t[a[j]];k<=j-1;k++){
					b[k]--;
				}		
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
