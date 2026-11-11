//GZ-J00530 ’≤ª€—˛ ∫Î“„÷–—ß
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100000],b[100000]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
    }
    for(int i=0;i<n;i++){
    	for(int s=i;s<n;s++){
    		for(int ss=s+1;ss<n;ss++){
    			if(a[s]==a[ss]){
    				for(int l=ss-1;l>=0;l++) a[l]=0;
				}
			}
		}
		for(int y=n-1;y>=0;y++){
			if(a[y]!=0){
				b[a[y]]++;
			}else break;
		}
	}
    for(int x=0;x<=m;x++){
    	cout<<b[x];
	}
	return 0;
}
