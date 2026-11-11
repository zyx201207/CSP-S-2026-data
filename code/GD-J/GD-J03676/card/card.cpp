#include <bits/stdc++.h>
using namespace std;
long long a,b,c,d,ar[500010],cr[500010],br[500050],dr[500050],e=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>a>>b;
	for (int i=1;i<=a;i++){
		cin>>br[i];
		if (br[i-1]<=br[i] and e==1){
			e=1;
		}else{
			e=0;
		}
	}
	if (e==0){
		for (int k=1;k<=a;k++){
		for (int i=1;i<=a;i++){
			ar[i]=0;
			cr[i]=0;
		}
		d=0;
		for (int i=k;i<=a;i++){
			c=br[i];
			if (cr[c]==0){
				ar[++d]=c;
				cr[c]=d;
			}else{
				for (int j=cr[c];j<=d;j++){
					ar[j]=0;	
				}
			d=cr[c];
			ar[d]=c;
			cr[c]=d;
			}
		}
		for (int i=1;i<=d;i++){
			dr[ar[i]]++;	
		}
	}
	for (int i=1;i<=b;i++){
		cout<<dr[i]<<" ";
	}
	}else{
		for (int i=1;i<=a;i++){
			cr[br[i]]=i;
		}
		for (int i=1;i<=b;i++){
			cout<<cr[i]<<" ";
		}
	}
		
	
	
	
	return 0;
}
