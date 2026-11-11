#include<bits/stdc++.h>
using namespace std;
struct node{
	long long a;
	char c;
}ac[200001];
int n,l,r;
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>ac[i].a>>ac[i].c;
	}while(l<r){
		if(ac[l].a<ac[r].a){
			if(ac[l].c!=ac[r].c){
				ans+=ac[l].a;
			}ac[r].a-=ac[l].a;
			l++;
		}else if(ac[l].a==ac[r].a){
			if(ac[l].c!=ac[r].c){
				ans+=ac[l].a;
			}l++;
			r--;
		}else{
			if(ac[l].c!=ac[r].c){
				ans+=ac[r].a;
			}ac[l].a-=ac[r].a;
			r--;
		}
	}cout<<ans;
	return 0;
}
