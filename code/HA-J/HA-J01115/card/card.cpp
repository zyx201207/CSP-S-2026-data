#include<bits/stdc++.h> 
using namespace std;
int n,m;
int a[100005],b[100005],r;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(!(n==0||m==0||m==1)){
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		if(n==1){
			cout<<1;
		}else{
			for(int x=0;x<m;x++){
				for(int i=x;i<n;i++){
				r=i;
				for(int j=0;j<r;j++){
					if(b[j]==a[i])r=j;
				}
				b[r]=a[i];r++;
			}
			}	
		}
	}
	return 0;
}
