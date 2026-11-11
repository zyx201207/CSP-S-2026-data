#include<bits/stdc++.h>
using namespace std;
int n;
long long s,ans;
struct node{
	int k;
	char c;
}ar[200010],br[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ar[i].k>>ar[i].c;
		br[n-i+1].k=ar[i].k;
		br[n-i+1].c=ar[i].c;
		s+=ar[i].k;
	}
	s/=2;
	
	int i=1,j=1;
	while(i<=n){
		if(ar[i].k>br[j].k){
			ar[i].k-=br[j].k;
			if(ar[i].c!=br[j].c){
				ans+=br[j].k;
			}br[j].k=0;
			j++;
		}else{
			br[j].k-=ar[i].k;
			if(ar[i].c!=br[j].c){
				ans+=ar[i].k;
			}ar[i].k=0;
			i++;
		}	
	}cout<<ans;
	return 0;
}
