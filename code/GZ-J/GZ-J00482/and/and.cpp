#include<bits/stdc++.h>
using namespace std;
int b,c,sum,num,maw[10000],xz,cs,bj[10000],zzg,h[10000],ai;
long long max=0;
int a[100000],jz[100010][100010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>b>>c;
	for(int i=1;i<=b;i++){
		cin>>a[i];
	}
	for(int i=1;i<=b;i++){
		num=a[i];
		int v=1;
		while(num==0){
			jz[i][v]=num%2;
			num/2;
			v++;
		}
		if(v>maw){
			maw[i]=v;
		}
	}
	for(int i=b;i>0;i--){
		cs+=i
	}
	cs-=c;
	while(xz==cs){
		for(int i=1;i<=b;i++){
			for(int j=i;j<=i+c-1;j++){
			    bj[i]=1;
			    if(maw[j]>zzg){
			    	zzg=maw[j];
				}
		    }
		    for(int k=1;k<=c;k++){
		    	for(int s=1;s<=zzg;s++){
		    		if(jz[bj[k]][s]==1){
		    			int h[s]==1;
					}
					else{
						h[s]==0;
					}
				}
		    }  
		}
	}
	int q=2;
	for(int i=zzg;i>0;i--){
		for(int k=1;k<=c;k++){
			q*=k	
	    }
			ai+=h[i]*(2*q)
			q++;
	}
	cout<<ai-1;
	return 0;
} 
