#include<bits/stdc++.h>
using namespace std;
const int M=1e5+10;
int n,m,cnt1=1;
int z[100000],t[200000],tt[200000],ansn[100000];
void cler(int z[]){
    for(int i=1;i<=m;i++){
    	z[i]=0;
	}
	return;
}
void ans(int t[],int ansn[]){
	for(int i=1;i<=cnt1;i++){
		ansn[t[i]]++;
	}
	return;
}
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);

cin>>n>>m;

	for(int i=1;i<=n;i++){
		cin>>tt[i];
	}
	for(int i=1;i<=n;i++){
		cler(z);
		cler(t);cnt1=1;	
		for(int j=i;j<=n;j++){
			t[cnt1]=tt[j];
			if(z[t[cnt1]]!=0){
		   		for(int q=z[t[cnt1]]+1;q<=cnt1;q++){
		   			if(q!=cnt1){
		   				z[t[q]]=0;
					}
		    	    t[q]=0;
				}
				cnt1=z[t[cnt1]];
			}
			else{
				z[t[cnt1]]=cnt1;
			}
			if(j==n){
				
			   ans(t,ansn);
			   continue;
			}
			cnt1++;
		}
		
		}
	for(int i=1;i<=m;i++){
		cout<<ansn[i]<<' ';
	}
		return 0;
	}