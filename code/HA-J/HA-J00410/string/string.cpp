#include<bits/stdc++.h> 
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	int l=0,r=n-1,cut=0;
	cin>>n;
	int nmb[n+2];
	string wod;
	for(int i=0;i<n;i++){
		cin>>nmb[i]>>wod[i];
	}
	while(l<=r){
		if(nmb[l]!=0&&nmb[r]!=0){
			char a=wod[l],b=wod[r];
			if(a!=b){
		    	cut++;
		    }
	    	nmb[l]-=1;
	    	nmb[r]-=1;
		}else if(nmb[l]==0){
			l++;
		}else{
			r++;
		}
	}
	cout<<cut<<endl;
	return 0;
}
