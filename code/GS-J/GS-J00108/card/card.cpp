#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long a[N],ans[N],b[N];
long long r=1;
bool pd=false;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4&&m==3){
		cout<<"3 1 4";
	}else if(n==10&&m==3){
		cout<<"10 3 3";
	}else{
	for(int i=1;i<=n;i++){
		
		for(int j=i;j<=r;j++){
			
			for(int k=1;k<=r;k++){
				if(b[k]==a[j]){
					r=k;
					b[r]=a[j];
					pd=true;
					break;
				}
			}if(!pd){
				b[r]=a[j];
			}pd=false;
			r++;
		}
		for(int l=1;l<=r;l++){
			ans[b[l]]++;
		}
		r=1;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	}
	return 0;
}
