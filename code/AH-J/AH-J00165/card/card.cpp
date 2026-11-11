#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("apple.in","r",stdin);
	freopen("apple.out","r",stdout);
	int a,b;
	cin>>a>>b;
	int l[a];
	int l1[a][a];
	int l2[a];
	int l3[a];
	for(int i=0;i<a;i++){
		cin>>l[i];
	}
	for(int m=0;m<a;m++){
		for(int i=0;i<a;i++){
			for(int j=0;j<a;j++){
				if(l2[j]==l[i]){
					for(int k=j;k<i;k++){
						l2[k]=0;
					}
				}
			}
			l2[i]=l[i];
		}
		for(int i=0;i<a;i++){
			l1[m][i]=l2[i];
		}
    }
    for(int m=0;m<a;m++){
    	for(int i=0;i<a;i++){
    		for(int j=0;j<a;j++){
    			if(l[m]==l1[i][j]){
    				l3[m]+=1;
				}
			}
		}
	}
	for(int i=0;i<a;i++){
		for(int j=i+1;j<a;j++){
			if(l3[i]==l3[j] && l3[i]!=0){
				l3[i]==0;
			}
		}
	}
	for(int i=0;i<a;i++){
		if(l3[i]!=0){
			cout<<l3[i]<<" ";
		}
	}
	return 0;
}
