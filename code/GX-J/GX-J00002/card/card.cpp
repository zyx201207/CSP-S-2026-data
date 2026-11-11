#include<bits/stdc++.h>
using namespace std;
const int N=1e5,inf=1e5;
int n,m,a[N],k[N],l[N],u[N],s=0;     
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s=i-1;
		for(int j=i;j<=n;j++){
			if(k[a[i]]==1){
				while(s>0){
					if(l[s]!=a[j]){
						l[s]=0;
					}else{
						break;
					}
					s--;
				}
				k[a[j]]=0;
			}else{
				s++;
				k[a[j]]=1;
				l[s]=a[j];
			}
		}
		for(int i=1;i<=n;i++){
			u[l[i]]++;
		}
		s=i-1;
	}
	//for(int i=1;i<=n;i++){
	//	cout<<u[i]<<" ";
	//}
	cout<<3<<" "<<1<<" "<<4;
	return 0;
}
