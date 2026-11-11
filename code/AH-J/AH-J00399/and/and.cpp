#include<bits/stdc++.h>
using namespace std;
long a[21111];
int main(){
	freeopen("and.in","r",stdin);
    freeopen("and.out","w",stdout);
    int n,m;
    int max=0,mk=0,max1=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	scanf("&d",&a[i]);
    	if(a[i]>mk){
    		mk=a[i];
		}
	}
	int pos1,pos2,pos3;
	if(m==1){
		cout<<mk;
	}
	else{
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				if((a[j]&a[i])>max){
					max=(a[j]&a[i]);
					pos1=i,pos2=j;
				}	
			}
		}
	}
	if(m==2){
		cout<<max;
	}
	if(m>2){
		a[pos1]=0,a[pos2]=0;
		while(m!=2){
			m-=1;
			int max1=(max&a[1]);
			for(int i=2;i<=n;i++){
				if(max1<(max&a[i])){
					max1=(max&a[i]);
					pos3=i;
				}
			}
			a[pos3]=0;
		}
		cout<<max1;
	}
	return 0;
}
