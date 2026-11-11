#include<bits/stdc++.h>
using namespace std;
long long a,b,c,e[35],e1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		scanf("%d",&c);
		int j=1;
		while(c){
			if(c%2==1){
				e[j++]++;
			}
			c/=2;
		}
    }
    for(int i=1;i<=32;i++){
    	if(e[i]>=b){
    		e1+=pow(2,i-1);
		}
	}
	cout<<e1;
	return 0;
} 

