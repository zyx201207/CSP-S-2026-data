#include<bits/stdc++.h>
using namespace std;	
struct node{
	int a;
	char c;
}mj[200010];
long long n,ans=0,l;
int main( ){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>mj[i].a>>mj[i].c;
		l+=mj[i].a;
	}	
	int i=1,j=n;
	while(i<=j){
	
		if(mj[i].c!=mj[j].c){
			if(mj[i].a>mj[j].a){
			ans+=mj[j].a;
			mj[i].a-=mj[j].a;
			j--;
			}
			else if(mj[i].a<mj[j].a){
			ans+=mj[i].a;
			mj[j].a-=mj[i].a;
			i++;
			}
			else if(mj[i].a==mj[j].a){
			ans+=mj[i].a;
			++i;
			--j;
			}
			
		}
		else if(mj[i].a>mj[j].a){
			
			mj[i].a-=mj[i].a;
			j--;
			}
			else if(mj[i].a<mj[j].a){
			
			mj[j].a-=mj[i].a;
			i++;
			}
			else if(mj[i].a==mj[j].a){
			i++;
			j--;
			}
	}
	cout<<ans;
	return 0;
}
