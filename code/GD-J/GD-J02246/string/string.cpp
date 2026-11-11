#include<bits/stdc++.h>
using namespace std;
int n;int cntt=0;
struct aaaoo{
	int ooo;
	char zizi;
}lll[200005];
int smsm=0;//freopen("travel.out","w",stdout);
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
    for(int i=0;i<n;i++)
    {
	    cin>>lll[i].ooo>>lll[i].zizi;
	    
	}
	int ppp=n-1;
	for(int i=0;i<n;i++){
	    while(lll[i].ooo!=0 and ppp!=i){
	    	if(lll[i].zizi==lll[ppp].zizi){
	    		int mmxx=min(lll[i].ooo,lll[ppp].ooo);
	    		lll[i].ooo-=mmxx;
	    		lll[ppp].ooo-=mmxx;
			}
			else{
				int mmxx=min(lll[i].ooo,lll[ppp].ooo);
	    		lll[i].ooo-=mmxx;
	    		lll[ppp].ooo-=mmxx;
	    		cntt+=mmxx;
			}
			if(lll[ppp].ooo==0)
			    ppp--;
		}
	}
	cout<<cntt;
	return 0;
}//拿不了满分AWA
//下午还要考S 
